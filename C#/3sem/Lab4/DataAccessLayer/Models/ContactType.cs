using System;
using System.Collections.Generic;
using System.Text;

namespace DataAccessLayer.Models
{
    public class ContactType
    {
        public int ContactTypeID { get; set; }
        public string Name { get; set; }
        public DateTime ModifiedDate { get; set; }
    }
}
