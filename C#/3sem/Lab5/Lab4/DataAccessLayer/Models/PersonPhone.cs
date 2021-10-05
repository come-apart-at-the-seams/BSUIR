using System;
using System.Collections.Generic;
using System.Text;

namespace DataAccessLayer.Models
{
    public class PersonPhone
    {
        public int BusinessEntityID { get; set; }
        public int EmailAddressID { get; set; }
        public string EmailAddres { get; set; }
        public Guid rowguid { get; set; }
        public DateTime ModifiedDate { get; set; }
    }
}
