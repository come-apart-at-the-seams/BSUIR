using System.ComponentModel;
using System.Configuration.Install;
using System.ServiceProcess;

namespace Lab2_Extract
{
    [RunInstaller(true)]
    public partial class Installer1 : Installer
    {
        private System.ComponentModel.IContainer components = null;

        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
        }

        ServiceInstaller serviceInstaller;
        ServiceProcessInstaller processInstaller;

        public Installer1()
        {
            InitializeComponent();
            serviceInstaller = new ServiceInstaller();
            processInstaller = new ServiceProcessInstaller();

            processInstaller.Account = ServiceAccount.LocalSystem;
            serviceInstaller.StartType = ServiceStartMode.Manual;
            serviceInstaller.ServiceName = "Service1";
            Installers.Add(processInstaller);
            Installers.Add(serviceInstaller);
        }
    }


}