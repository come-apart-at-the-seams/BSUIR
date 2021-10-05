using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Extract
{
    public interface IConfigParser<T> where T : class
    {
        T Settings { get; set; }
        T Parse(string parserPath);
    }
}
