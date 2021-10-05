using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace DataAccessLayer.Models
{
    public class Person
    {
        public BusinessEntity BusinessEntity { get; set; }
        public ContactType    ContactType    { get; set; }
        public CountryRegion  CountryRegion  { get; set; }
        public EmailAddress   EmailAddress   { get; set; }
        public PersonPhone    PersonPhone    { get; set; }


        public Person()
        {

        }

        


        public Person(BusinessEntity BusinessEntity, ContactType ContactType,
                      PersonPhone PersonPhone, CountryRegion CountryRegion,
                      EmailAddress EmailAddress)
        {
            this.BusinessEntity = BusinessEntity;
            this.ContactType = ContactType;
            this.PersonPhone = PersonPhone;
            this.CountryRegion = CountryRegion;
            this.EmailAddress = EmailAddress;
        }
    }
}
