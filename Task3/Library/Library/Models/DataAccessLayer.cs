using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;

namespace Library.Models
{
    public class DataAccessLayer
    {
        LibraryContext db = new LibraryContext();

        public IEnumerable<Datas> GetAllDatas()
        {
            try
            {
                return db.Datas.ToList();
            }
            catch
            {
                throw;
            }
        }

        public int AddBook(Datas book)
        {
            try
            {
                db.Datas.Add(book);
                db.SaveChanges();
                return 1;
            }
            catch
            {
                throw;
            }
        }

        public int EditBook(Datas book)
        {
            try
            {
                db.Entry(book).State = EntityState.Modified;
                db.SaveChanges();
                return 1;
            }
            catch
            {
                throw;
            }
        }

        public Datas GetBookDetails(int id)
        {
            try
            {
                Datas book = db.Datas.Find(id); ;
                return book;
            }
            catch
            {
                throw; ;
            }
        }

        public int DeleteBook(int id)
        {
            try
            {
                Datas book = db.Datas.Find(id);
                db.Datas.Remove(book);
                db.SaveChanges();
                return 1;
            }
            catch
            {
                throw;
            }
        }

        public IEnumerable<Datas> GetYearList()
        {
            //List<short> yearList = new List<short>();
            return (from Year in db.Datas select Year).Distinct().OrderBy(y => y.Year).ToList();
            //var yearList = new SelectList(years.OrderBy(y => y.Year), "Year", "Year");
            //var yearL = db.Datas.Select(obj => obj.Year).Distinct().OrderBy(y => y).ToList();
            //return years.ConvertAll(x => (short)x);
        }
         

    }
}
