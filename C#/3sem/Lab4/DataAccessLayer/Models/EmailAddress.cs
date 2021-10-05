using System;
using System.Collections.Generic;
using System.Text;

namespace DataAccessLayer.Models
{
    public class EmailAddress
    {
        public int BusinessEntityID { get; set; }
        public int EmailAddressID { get; set; }
        public string EmailAddres { get; set; }
        public Guid Rowguid { get; set; }
        public DateTime ModifiedDate { get; set; }
    }
}
