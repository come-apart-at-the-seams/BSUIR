from info import *
from Lab1 import generate_samps
from Lab2 import generate_data_for_f_via_intervals, generate_data_for_f_via_probabilities

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button

from scipy import stats


init_n = 20
init_trust = 0.95

plot_trust = 10**2



def StudentValue(alpha, freedom):
    return stats.t.ppf(alpha, freedom)

def ChiSquareValue(alpha, freedom): 
    return stats.chi2.ppf(alpha, freedom)
    
def InverseLaplaceValue(value):
    value += 1/2
    L, R = 0, 10
    while True:
        x = (L+R)/2
        laplace = stats.norm.cdf(x)
        if abs(laplace - value) < 10**-6: return x
        elif laplace < value: L = x
        elif laplace > value: R = x


def PointExpectedValue(samps):
    return sum(samps) / len(samps)

def PointUnbiasedVariance(samps):
    xavg = PointExpectedValue(samps)
    return sum((x - xavg)**2 for x in samps) / (len(samps) - 1)


def ConfidenceIntervalOfExpectedValue(Trust, Samps=None, SampsSize=None, ExpectedValue=None, Variance=None, Student=False):
    if Samps is None:
        n = SampsSize
        xavg = ExpectedValue
        S = Variance ** (1/2)
        if Student:
            delta = StudentValue(1-(1-Trust)/2, n-1) * S / n**(1/2)
        else:
            delta = InverseLaplaceValue(Trust/2) * S / n**(1/2)
    else:
        n = len(Samps)
        xavg = ExpectedValue or PointExpectedValue(Samps)
        if Variance is None:
            S = PointUnbiasedVariance(Samps) ** (1/2)
            delta = StudentValue(1-(1-Trust)/2, n-1) * S / n**(1/2)
        else:
            S = Variance ** (1/2)
            delta = InverseLaplaceValue(Trust/2) * S / n**(1/2)
    return (xavg - delta, xavg + delta)

def ConfidenceIntervalOfVariance(Trust, Samps=None, SampsSize=None, ExpectedValue=None, Variance=None):
    n = SampsSize or len(Samps)
    if Samps is not None and ExpectedValue is not None and Variance is None:
        ss = sum((x - ExpectedValue)**2 for x in Samps) / n
        deltaleft = n * ss / ChiSquareValue((1+Trust)/2, n)
        deltaright = n * ss / ChiSquareValue((1-Trust)/2, n)
    else:
        ss = Variance or PointUnbiasedVariance(Samps)
        deltaleft = (n-1) * ss / ChiSquareValue((1+Trust)/2, n-1)
        deltaright = (n-1) * ss / ChiSquareValue((1-Trust)/2, n-1)
    return (deltaleft, deltaright)


speclines = []

def RemoveSpecLines():
    global speclines
    for line in speclines:
        line.remove()
    speclines.clear()

def PrintConfidenceIntervalOfSomething(method, expect, title=None, **method_kwargs):

    plt.title(title or '', fontsize=15)
    
    yplot = np.linspace(0, 1-1/plot_trust, plot_trust)
    interval = [method(Trust=y, **method_kwargs) for y in yplot]
    xplot = [expect for y in yplot]
    errors = [[expect - interval[i][0] for i in range(len(yplot))], 
              [interval[i][1] - expect for i in range(len(yplot))]]
    plt.errorbar(xplot, yplot, xerr=errors, linewidth=3)
    
    errors = []
    special = [0.9, 0.95, 0.99, 0.999]
    represented = []
    for trust in special:
        for index in range(len(yplot)):
            if abs(trust - yplot[index]) < 10**-6:
                errors += [interval[index]]
                represented += [trust]
    xplot = [expect for i in range(len(errors))]
    yplot = represented
    errors = [[expect - errors[i][0] for i in range(len(errors))], 
              [errors[i][1] - expect for i in range(len(errors))]]
    
    global speclines
    speclines.append( plt.errorbar(xplot, yplot, xerr=errors, color='black', linewidth=3) )
    
    plt.errorbar([expect, expect], [0, 1], color='black', linewidth=3)
    

def test_it_test():

    def almost_same(a, b, eps=0.01): return abs(a-b) < eps
    def almost_same_pair(a, b, eps=0.01): return almost_same(a[0], b[0], eps) and almost_same(a[1], b[1], eps)
    
    
    interval = ConfidenceIntervalOfExpectedValue(Trust=0.95, SampsSize=100, ExpectedValue=24.15, Variance=25)
    assert almost_same_pair( interval, (23.17,25.13) )
    
    interval = ConfidenceIntervalOfExpectedValue(Trust=0.99, SampsSize=100, ExpectedValue=93, Variance=400)
    assert almost_same_pair( interval, (87.84,98.16) )
    
    interval = ConfidenceIntervalOfExpectedValue(Trust=0.95, Samps=[7.1,6.3,6.2,5.8,7.7,6.8,6.7,5.9,5.7,5.1])
    assert almost_same_pair( interval, (5.79,6.87) )
    
    interval = ConfidenceIntervalOfExpectedValue(Trust=0.999, SampsSize=20, ExpectedValue=76, Variance=121, Student=True)
    assert almost_same_pair( interval, (66.45,85.55) )
    
    
    interval = ConfidenceIntervalOfVariance(Trust=0.95, SampsSize=10, Variance=0.5776)
    assert almost_same_pair( np.sqrt(interval), (0.52,1.39) )
    
    interval = ConfidenceIntervalOfExpectedValue(Trust=0.9, SampsSize=100, ExpectedValue=18.52, Variance=5.45409316)
    assert almost_same_pair( interval, (18.13,18.91) )
    interval = ConfidenceIntervalOfVariance(Trust=0.9, SampsSize=100, ExpectedValue=18.52, Variance=5.45409316)
    assert almost_same_pair( np.sqrt(interval), (2.09,2.65) )
    
    
    samps = [8.3, 8.6, 8.7, 8.8, 9.1, 9.3, 9.4, 13.4, 13.5, 13.8, 13.9, 14.1, 14.3]
    interval = ConfidenceIntervalOfExpectedValue(Trust=0.95, Samps=samps)
    assert almost_same_pair( interval, (9.6,12.7), eps=0.1 )
    #interval = ConfidenceIntervalOfVariance(Trust=0.95, Samps=samps)
    #print( interval, (1.4,14.3) )
    #assert almost_same_pair( interval, (1.4,14.3), eps=0.1 )
    

if __name__ == "__main__":

    test_it_test()

    print(f"n = {init_n}")
    
    init_samps = generate_samps(init_n)
    samps = init_samps
    
    print(f'Реальное матожидание        = {M():.6f}')
    print(f'Точечная оценка матожидания = {PointExpectedValue(init_samps):.6f}')
    interval = ConfidenceIntervalOfExpectedValue(Trust=init_trust, Samps=init_samps)
    print(f'Доверительный интервал M при НЕизвестной D для {init_trust} = ({interval[0]:.6f}, {interval[1]:.6f}); Попало? {interval[0] < M() < interval[1]}')
    interval = ConfidenceIntervalOfExpectedValue(Trust=init_trust, Samps=init_samps, Variance=D())
    print(f'Доверительный интервал M при   известной D для {init_trust} = ({interval[0]:.6f}, {interval[1]:.6f}); Попало? {interval[0] < M() < interval[1]}')
    print(f'Реальная дисперсия                    = {D():.6f}')
    print(f'Точечная оценка несмещённой дисперсии = {PointUnbiasedVariance(init_samps):.6f}')
    interval = ConfidenceIntervalOfVariance(Trust=init_trust, Samps=init_samps)
    print(f'Доверительный интервал D при НЕизвестной M для {init_trust} = ({interval[0]:.6f}, {interval[1]:.6f}); Попало? {interval[0] < D() < interval[1]}')
    interval = ConfidenceIntervalOfVariance(Trust=init_trust, Samps=init_samps, ExpectedValue=M())
    print(f'Доверительный интервал D при   известной M для {init_trust} = ({interval[0]:.6f}, {interval[1]:.6f}); Попало? {interval[0] < D() < interval[1]}')
    print()
    
    
    fig, ax = plt.subplots()
    
    n_slider = Slider(
        ax=plt.axes([0.15, 0.02, 0.5, 0.03]),
        label='n = 2 ^ ',
        valmin=1,
        valmax=10,
        valinit=np.log2(init_n + 1/2),
    )
    button_clear = Button(plt.axes([0.85, 0.01, 0.10, 0.05]), 'Clear')
    button_generate = Button(plt.axes([0.7, 0.01, 0.10, 0.05]), 'Generate')
    subplots = [plt.subplot(221), plt.subplot(222), plt.subplot(223), plt.subplot(224)]
    
    def generate(trash):
        global samps
        if samps != init_samps:
            samps = generate_samps(int(2**n_slider.val))
        RemoveSpecLines()
        plt.axes(subplots[0])
        PrintConfidenceIntervalOfSomething(ConfidenceIntervalOfExpectedValue, M(), Samps=samps, 
            title='Доверительный интервал M с НЕизвестной D')
        plt.axes(subplots[1])
        PrintConfidenceIntervalOfSomething(ConfidenceIntervalOfExpectedValue, M(), Samps=samps, Variance=D(), 
            title='Доверительный интервал M с известной D')
        plt.axes(subplots[2])
        PrintConfidenceIntervalOfSomething(ConfidenceIntervalOfVariance, D(), Samps=samps, 
            title='Доверительный интервал D с НЕизвестной M')
        plt.axes(subplots[3])
        PrintConfidenceIntervalOfSomething(ConfidenceIntervalOfVariance, D(), Samps=samps, ExpectedValue=M(),
            title='Доверительный интервал D с известной M')
        fig.canvas.draw_idle()
        if samps == init_samps:
            samps = None
    
    def clear(trash):
        global subplots
        for plot in subplots:
            plot.clear()
        generate(trash)
    
    button_clear.on_clicked(clear)
    button_generate.on_clicked(generate)
    n_slider.on_changed(generate)
    
    generate(None)
    
    plt.show()
