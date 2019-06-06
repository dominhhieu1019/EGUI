using System.Collections.Generic;
using System.Linq;
using LibraryMVC.Models;
using Microsoft.AspNetCore.Mvc;
using System.Web.Http.Cors;
//using System.Web.Http;

namespace EguiApi.Controllers {
    //[EnableCors(origins: "*", headers: "*", methods: "*")]
    //[EnableCors("MyPolicy")]
    //[Route("api/[controller]")]
    public class LibraryController : Controller {
        private const string V = "{title}/{author}/{year}";

        List<Book> library = Library.GetLibrary();

        // GET api/Library
        [HttpGet]
        [Route("api/Library/Index")]
        public IEnumerable<Book> Get() {
            return library;
        }

        // GET api/Library/3
        [HttpGet("{id}")]
        [Route("api/Library/Index/{id}")]
        public Book Get(int id) {
            return Library.GetLibrary().FirstOrDefault(p => p.Id == id);
        }

        [HttpPost(V)]
        [Route("api/Library/Create/{title}/{author}/{year}")]
        public void Create(string title, string author, int year)
        {
            Library.AddBook(title, author, year);
        }

        [HttpPut("{id}/{title}/{author}/{year}")]
        [Route("api/Library/Edit/{id}/{title}/{author}/{year}")]
        public void Edit(int id, string title, string author, int year)
        {
            Library.EditBook(id, title, author, year);
        }

        
        [HttpDelete("{id}")]
        [Route("api/Library/Delete/{id}")]
        public void Delete(int id)
        {
            Library.DeleteBook(id);
            //int index = Library.GetLibrary().FindIndex(x => x.Id == id);
            //Library.GetLibrary().RemoveAt(id);
        }

        [HttpGet]
        [Route("api/Library/GetYearList")]
        public List<int> GetYearList() {
            return Library.GetYearList();
        } 

        [HttpGet("{titleFilter}/{authorFilter}/{yearFilter}")]
        [Route("api/Library/{titleFilter}/{authorFilter}/{yearFilter}")]
        public void GetFilter() {
        }
    }
}