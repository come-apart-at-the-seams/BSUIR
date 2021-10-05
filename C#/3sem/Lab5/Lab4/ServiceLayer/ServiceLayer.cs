using DataAccessLayer.Models;
using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using Logger;

namespace ServiceLayer
{
    public class ServiceLayer : IServiceLayer
    {
        logger log = new logger();
        public DataAccessLayer.DataAccessLayer dal;
        public ServiceLayer(DataAccessLayer.Options.ConnectionOptions options)
        {
            dal = new DataAccessLayer.DataAccessLayer(options);
        }

        public List<Person> GetPersonList()
        {
            List<Person> personList = new List<Person>();

            List<BusinessEntity> be = dal.GetAllInstances<BusinessEntity>();
            List<ContactType>    ct = dal.GetAllInstances<ContactType>();
            List<CountryRegion>  cr = dal.GetAllInstances<CountryRegion>();
            List<EmailAddress>   ea = dal.GetAllInstances<EmailAddress>();
            List<PersonPhone>    pp = dal.GetAllInstances<PersonPhone>();


            for (int i = 0; i < be.Count; i++)
            {
                personList.Add(new Person(be[i], ct[i], pp[i], cr[i], ea[i]));
            }
            log.AddToLog("GetPersonList: OK\n");
            return personList;
        }


        public async Task<List<Person>> GetPersonListAsync()
        {
            List<Person> personList = new List<Person>();
            
            
            
                List<BusinessEntity> be = await dal.GetAllInstancesAsync<BusinessEntity>();
                List<ContactType> ct = await dal.GetAllInstancesAsync<ContactType>();
                List<CountryRegion> cr = await dal.GetAllInstancesAsync<CountryRegion>();
                List<EmailAddress> ea = await dal.GetAllInstancesAsync<EmailAddress>();
                List<PersonPhone> pp = await dal.GetAllInstancesAsync<PersonPhone>();
                for (int i = 0; i < be.Count; i++)
                {
                    personList.Add(new Person(be[i], ct[i], pp[i], cr[i], ea[i]));
                }


            //log.AddToLog("GetPersonListAsync: OK\n");

            return personList;
        }
    }
}
