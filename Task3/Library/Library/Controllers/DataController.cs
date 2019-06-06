using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Library.Models;
using System.Web.Http.Cors;


// For more information on enabling Web API for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace Library.Controllers
{
    [EnableCors(origins: "http://localhost:54744", headers: "*", methods: "*")]

   // [Route("api/[controller]")]
    public class DataController : Controller
    {
        private DataAccessLayer objdata = new DataAccessLayer();

        public DataController()
        {
            objdata = new DataAccessLayer();
        }
        // GET: api/<controller>
        [HttpGet]
        [Route("api/Data/Index")]
        public IEnumerable<Datas> Get()
        {
            return objdata.GetAllDatas();
        }

        // GET api/<controller>/5
        [HttpGet]
        [Route("api/Data/Details/{id}")]
        public Datas Details(int id)
        {
            return objdata.GetBookDetails(id);
        }

        // POST api/<controller>
        [HttpPost]
        [Route("api/Data/Create")]
        public int Create(Datas book)
        {
            return objdata.AddBook(book);
        }

        // PUT api/<controller>/5
        [HttpPut]
        [Route("api/Data/Edit")]
        public int Edit(Datas book)
        {
            return objdata.EditBook(book);
        }

        // DELETE api/<controller>/5
        [HttpDelete]
        [Route("api/Data/Delete/{id}")]
        public int Delete(int id)
        {
            return objdata.DeleteBook(id);
        }
    }
}
