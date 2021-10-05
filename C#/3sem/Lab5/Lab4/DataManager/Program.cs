using ServiceLayer;
using Lab2_Extract;
using DataAccessLayer;
using DataAccessLayer.Options;
using DataAccessLayer.Models;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace DataManager
{
    class Program
    {
        static async Task Main(string[] args)
        {
            List<Person> list;



            ConnectionOptions connectionOptions = new ConnectionOptions();
            ServiceLayer.ServiceLayer serviceLayer = 
                new ServiceLayer.ServiceLayer(connectionOptions);
            //list = serviceLayer.GetPersonList();


            DirectoryOptions dirOptions = new DirectoryOptions();
            XmlGenerator xmlGenerator = new XmlGenerator(dirOptions);
            //xmlGenerator.ListToXml(list, dirOptions);


            //Monitoring.Update();

            
            list = await serviceLayer.GetPersonListAsync();


            xmlGenerator.ListToXml(list, dirOptions);


            Monitoring.Update();

            //Console.WriteLine("Hello World!");
        }
    }
}
