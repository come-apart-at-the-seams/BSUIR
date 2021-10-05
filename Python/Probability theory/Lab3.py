from info import *
from Lab1 import generate_samps
from Lab2 import generate_data_for_f_via_intervals, generate_data_for_f_via_probabilities

import numpy as np
import matplotlib.pyplot as plt

from scipy import stats


ChiSquareHypothesisN = 200
KolmogorovHypothesisN = 30
MisesHypothesisN = 50


test_n = 100
tests = 10**3

def ChiSquareIntervalsCount(samps): return int(round(len(samps)**(1/3) + 1/2))



def OptimalIntervalsCount(samps):
    n = len(samps)
    IQR = samps[int(round(3*n/4))-1] - samps[int(round(1*n/4))-1]
    width = 2 * IQR / n**(1/3)
    m = int((samps[-1] - samps[0]) / width)
    return m
    
def ChiSquareValue(samps):
    m = ChiSquareIntervalsCount(samps)
    xdots, ydots = generate_data_for_f_via_probabilities(samps, m)
    n = len(samps)
    if m > n: m = n
    chi = 0.0
    probsum = 0.0
    for i in range(1, m+1):
        trueprob = F(xdots[i]) - F(xdots[i-1])
        sampprob = 1/m
        chi += n * (sampprob - trueprob)**2 / trueprob
        probsum += trueprob
    #if probsum < 0.99: return +np.inf
    return chi

def ChiSquareCritical(alpha, df): 
    return stats.chi2.ppf(alpha, df)

def ChiSquareHypothesis(samps):
    df = ChiSquareIntervalsCount(samps) - 1
    chi = ChiSquareValue(samps)
    print(f"ChiSquare = {chi:.6f}")
    def CompareWith(alpha):
        print(f'{alpha:.2f}:  < {ChiSquareCritical(alpha, df):.4f} ? {chi < ChiSquareCritical(alpha, df)}')
    CompareWith(0.90)
    CompareWith(0.95)
    CompareWith(0.99)


def KolmogorovValue(samps):
    n = len(samps)
    d = 0.0
    for i in range(n):
        d = max(d, max( abs(F(samps[i]) - i/n) , abs(F(samps[i]) - (i+1)/n) ))
    l = d * n**0.5 + 1 / (6 * n**0.5)
    return l

def KolmogorovCritical(alpha):
    return stats.kstwobign.ppf(alpha)

def KolmogorovHypothesis(samps):
    l = KolmogorovValue(samps)
    print(f"Kolmogorov = {l:.6f}")
    def CompareWith(alpha):
        print(f'{alpha:.2f}:  < {KolmogorovCritical(alpha):.4f} ? {l < KolmogorovCritical(alpha)}')
    CompareWith(0.90)
    CompareWith(0.95)
    CompareWith(0.99)


def MisesValue(samps):
    n = len(samps)
    nw = 1/(12*n)
    for i in range(n):
        nw += (F(samps[i]) - (i-0.5)/n)**2
    return nw

def MisesCritical(alpha):
    if alpha == 0.99: return 0.7435
    if alpha == 0.95: return 0.4614
    if alpha == 0.90: return 0.3473
    raise ValueError

def MisesHypothesis(samps):
    nw = MisesValue(samps)
    print(f"Mises = {nw:.6f}")
    def CompareWith(alpha):
        print(f'{alpha:.2f}:  < {MisesCritical(alpha):.4f} ? {nw < MisesCritical(alpha)}')
    CompareWith(0.90)
    CompareWith(0.95)
    CompareWith(0.99)



if __name__ == "__main__":

    print(f"\n Является ли '{EmpiricName()}' распределение — '{AnalyticName()}' ? \n")
    
    print(f"ChiSquareHypothesis, n = {ChiSquareHypothesisN}")
    ChiSquareHypothesis(generate_samps(ChiSquareHypothesisN))
    print()
    
    print(f"KolmogorovHypothesis, n = {KolmogorovHypothesisN}")
    KolmogorovHypothesis(generate_samps(KolmogorovHypothesisN))
    print()
    
    print(f"MisesHypothesis, n = {MisesHypothesisN}")
    MisesHypothesis(generate_samps(MisesHypothesisN))
    print()
    
    print("Реальная вероятность того, что выборка соответствует критерию:")
    
    print(f"n = {test_n}")
    print(f"tests = {tests}")
    
    ChiSquaresValues, KolmogorovValues, MisesValues = [],[],[]
    ChiSquaresOK = {0.90: 0, 0.95: 0, 0.99: 0}
    ChiSquaresFreedomDegrees = []
    for _ in range(tests):
        samps = generate_samps(test_n)
        ChiSquaresValues += [ChiSquareValue(samps)]
        for alpha in ChiSquaresOK.keys():
            ChiSquaresFreedomDegrees += [ChiSquareIntervalsCount(samps) - 1]
            if ChiSquaresValues[-1] < ChiSquareCritical(alpha, ChiSquaresFreedomDegrees[-1]): 
                ChiSquaresOK[alpha] += 1
        KolmogorovValues += [KolmogorovValue(samps)]
        MisesValues += [MisesValue(samps)]
    ChiSquaresValues.sort()
    KolmogorovValues.sort()
    MisesValues.sort()
    
    def CheckCriterionPercentage(alpha):
        print()
        print(f"ChiSquare({alpha})  == {ChiSquaresOK[alpha] / tests}")
        print(f"Kolmogorov({alpha}) == {sum([(1 if val < KolmogorovCritical(alpha) else 0) for val in KolmogorovValues]) / tests}")
        print(f"Mises({alpha})      == {sum([(1 if val < MisesCritical(alpha) else 0) for val in MisesValues]) / tests}")
    CheckCriterionPercentage(0.9)
    CheckCriterionPercentage(0.95)
    CheckCriterionPercentage(0.99)
    
    
    plt.suptitle(f"   Распределение статистических критериев для различных выборок одного объёма" + \
                 f"\n Является ли '{EmpiricName()}' распределение — '{AnalyticName()}' ?" + \
                 f"\n Объём выборки = {test_n}; Кол-во генераций = {tests}",
                 fontsize=15)
    
    plt.subplot(311)
    plt.ylabel("Хи-квадрат", fontsize=15)
    
    xplot = np.linspace(0, max(ChiSquaresValues), 10**3)
    yplot = [stats.chi2.pdf(x, sorted(ChiSquaresFreedomDegrees)[tests//2]) for x in xplot]
    plt.plot(xplot, yplot, linewidth=3, color='grey')
    
    plt.step(*generate_data_for_f_via_probabilities(ChiSquaresValues, OptimalIntervalsCount(ChiSquaresValues)),
             where='pre', linewidth=1, color='red')
    plt.step(*generate_data_for_f_via_intervals(ChiSquaresValues, OptimalIntervalsCount(ChiSquaresValues)),
             where='pre', linewidth=2, color='blue')


    plt.subplot(312)
    plt.ylabel("Колмогоров", fontsize=15)
    
    xplot = np.linspace(0, max(KolmogorovValues), 10**3)
    yplot = [stats.kstwobign.pdf(x) for x in xplot]
    plt.plot(xplot, yplot, linewidth=3, color='grey')
    
    plt.step(*generate_data_for_f_via_probabilities(KolmogorovValues, OptimalIntervalsCount(KolmogorovValues)),
             where='pre', linewidth=1, color='red')
    plt.step(*generate_data_for_f_via_intervals(KolmogorovValues, OptimalIntervalsCount(KolmogorovValues)),
             where='pre', linewidth=2, color='blue')


    plt.subplot(313)
    plt.ylabel("Мизес", fontsize=15)
    
    xplot = [0, 1/30, 1/20, 1/13, 1/11, 1/10, 1/7,  1/5,  1/4,  1/3,  1/2,  1]
    yplot = [0, 3.45, 5.20, 5.65, 5.40, 4.85, 3.40, 2.10, 1.45, 0.75, 0.30, 0]
    plt.plot(xplot, yplot, linewidth=3, color='grey')
    
    plt.step(*generate_data_for_f_via_probabilities(MisesValues, OptimalIntervalsCount(MisesValues)),
             where='pre', linewidth=1, color='red')
    plt.step(*generate_data_for_f_via_intervals(MisesValues, OptimalIntervalsCount(MisesValues)),
             where='pre', linewidth=2, color='blue')
    
    
    plt.show()

