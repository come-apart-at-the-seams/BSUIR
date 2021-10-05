using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataAccessLayer.Options;

namespace Lab2_Extract
{
    interface IXmlGeneratorService<T> where T : class
    {
        void ListToXml(List<T> list, DirectoryOptions options);
    }
}
