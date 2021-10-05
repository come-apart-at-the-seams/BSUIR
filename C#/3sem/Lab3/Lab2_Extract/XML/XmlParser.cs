using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Lab2_Extract
{
    class XmlParser : IConfigParser<string[]>
    {
        public string[] Settings { get; set; }

        public string[] Parse(string parserPath)
        {
            //string xml;
            List<string> list = new List<string>();
            //List<T> l = new List<T>();

            XmlSerializer formatter = new XmlSerializer(typeof(EtlXmlOptions),
                                                        new XmlRootAttribute("root"));

            EtlXmlOptions deserialed;

            using (FileStream file = new FileStream(parserPath,
                                        FileMode.Open))
            {
                
                using (StreamReader reader = new StreamReader(file))
                {
                    //xml = reader.ReadToEnd();
                    deserialed = (EtlXmlOptions)formatter.Deserialize(reader);
                }
            }
            //Console.WriteLine(xml);

            
            //var deserialed = JsonConvert.DeserializeObject<EtlJsonOptions>(json);
            

            list.Add(deserialed.TargetDirectory.ToString());
           


            // НАДО ИЗ СТРИНГ  СДЕЛАТЬ МАССИВ БАЙТОВ 
            string[] keys = deserialed.Key.Split(' ');
            string[] ivs = deserialed.Iv.Split(' ');

            foreach (string k in keys)
            {
                list.Add(k.ToString());
               
            }
            foreach (string k in ivs)
            {
                list.Add(k.ToString());
            }

            string[] settings = list.ToArray();


            //foreach (string l in settings)
            //{
            //    Console.WriteLine(l);
            //}
            return settings;
        }

        public XmlParser(string parserPath)
        {
            Settings = Parse(parserPath);
        }
    }
}
