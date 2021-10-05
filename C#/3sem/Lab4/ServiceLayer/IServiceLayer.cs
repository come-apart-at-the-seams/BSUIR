using DataAccessLayer.Models;
using System.Collections.Generic;

namespace ServiceLayer
{
    public interface IServiceLayer
    {
        List<Person> GetPersonList();
    }
}
