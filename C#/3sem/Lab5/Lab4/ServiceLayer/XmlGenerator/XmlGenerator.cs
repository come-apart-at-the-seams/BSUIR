using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using DataAccessLayer.Models;
using DataAccessLayer.Options;
using Logger;

namespace Lab2_Extract
{
    public class XmlGenerator : IXmlGeneratorService<Person>
    {
        logger log = new logger();
        public XmlGenerator(DirectoryOptions options)
        {
            Directory.CreateDirectory(options.SoursceDirectory);
        }


        public async void ListToXml(List<Person> list, DirectoryOptions options)
        {

                XmlSerializer xml = new XmlSerializer(list.GetType());

            await Task.Run(() =>
            {
                using (FileStream fs = new FileStream(Path.Combine(options.SoursceDirectory,
                                                      "list.xml"), FileMode.Create))
                {
                    xml.Serialize(fs, list);
                }

                log.AddToLog("ListToXml: OK\n");
            });
        }
    }
}
