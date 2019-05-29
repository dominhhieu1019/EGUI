using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using Library.Models;
using System.ComponentModel;
using System.Linq.Dynamic;
using System.Linq.Expressions;
using System.Reflection;

namespace Library.Controllers
{
    public class DataController : Controller
    {
        private LIBRARYEntities db = new LIBRARYEntities();

        public class HttpParamActionAttribute : ActionNameSelectorAttribute
        {
            public override bool IsValidName(ControllerContext controllerContext, string actionName, MethodInfo methodInfo)
            {
                if (actionName.Equals(methodInfo.Name, StringComparison.InvariantCultureIgnoreCase))
                    return true;

                var request = controllerContext.RequestContext.HttpContext.Request;
                return request[methodInfo.Name] != null;
            }
        }

        // GET: Data
        public ActionResult Index(string sortProperty, string sortOrder, string titleSearch, string authorSearch, short yearSearch = 0)
        {
            //1. Keep sort status
            if (sortOrder == "asc") ViewBag.SortOrder = "desc";
            if (sortOrder == "desc") ViewBag.SortOrder = "";
            if (sortOrder == "") ViewBag.SortOrder = "asc";

            //1.1. Create list year 
            var years = from y in db.Datas select y;
            
            ViewBag.yearSearch = new SelectList(years.OrderBy(y => y.Year), "Year", "Year");

            //1.2. Keep search values
            ViewBag.titleSearchValue = titleSearch;
            ViewBag.authorSearchValue = authorSearch;
            //ViewBag.yearSearchValue = yearSearch;

            //2. Get all properties of class Data
            var properties = typeof(Data).GetProperties();

            //Name order
            List<Tuple<string, bool, int>> list = new List<Tuple<string, bool, int>>();
            foreach (var item in properties)
            {
                int order = 999;
                var isVirtual = item.GetAccessors()[0].IsVirtual;

                if (item.Name == "ID") continue;
                if (item.Name == "Title") order = 1;
                if (item.Name == "Author") order = 2;
                if (item.Name == "Year") order = 3;
            
                Tuple<string, bool, int> t = new Tuple<string, bool, int>(item.Name, isVirtual, order);
                list.Add(t);
            }

            //2.1. Sort by above order
            list = list.OrderBy(x => x.Item3).ToList();

            foreach (var item in list)
            {
                // 2.2. Sort if normal properties
                if (!item.Item2) 
                {
                    // 2.3. Change sort symbol
                    if (sortOrder == "desc" && sortProperty == item.Item1)
                    {
                        ViewBag.Headings += "<th><a href='?sortProperty=" + item.Item1 + "&sortOrder=" +
                            ViewBag.SortOrder + "&titleSearch=" + titleSearch + "&authorSearch=" + authorSearch + "&yearSearch=" + yearSearch + "'>" + 
                            item.Item1 + "<i class='fa fa-sort-down'></i></a></th>";
                    }
                    else if (sortOrder == "asc" && sortProperty == item.Item1)
                    {
                        ViewBag.Headings += "<th><a href='?sortProperty=" + item.Item1 + "&sortOrder=" +
                            ViewBag.SortOrder + "&titleSearch=" + titleSearch + "&authorSearch=" + authorSearch + "&yearSearch=" + yearSearch + "'>" + 
                            item.Item1 + "<i class='fa fa-sort-up'></i></a></th>";
                    }
                    else
                    {
                        ViewBag.Headings += "<th><a href='?sortProperty=" + item.Item1 + "&sortOrder=" +
                           ViewBag.SortOrder + "&titleSearch=" + titleSearch + "&authorSearch=" + authorSearch + "&yearSearch=" + yearSearch + "'>" + 
                           item.Item1 + "</a></th>";
                    }

                }
                // 2.4. Virtual properties no sort
                else ViewBag.Headings += "<th>" + item.Item1 + "</th>";
            }

            //3. Query all data
            var datas = from d in db.Datas select d;

            //4. Default sort property
            if (String.IsNullOrEmpty(sortProperty))
                sortProperty = "Title";

            // 5. Sort by order
            if (sortOrder == "desc")
                datas = datas.OrderBy(sortProperty + " desc");
            else if (sortOrder == "asc")
                datas = datas.OrderBy(sortProperty);

            //6. Search
            if (!String.IsNullOrEmpty(titleSearch))
                datas = datas.Where(s => s.Title.Contains(titleSearch));

            if (!String.IsNullOrEmpty(authorSearch))
                datas = datas.Where(s => s.Author.Contains(authorSearch));

            if (yearSearch != 0)
                datas = datas.Where(s => s.Year == yearSearch);

            return View(datas.ToList());
        }

        [HttpPost, HttpParamAction]
        public ActionResult Reset()
        {
            ViewBag.searchValue = "";
            Index("", "", "","");
            return View();
        }


        // GET: Data/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Data data = db.Datas.Find(id);
            if (data == null)
            {
                return HttpNotFound();
            }
            return View(data);
        }

        // GET: Data/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Data/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "ID,Title,Author,Year")] Data data)
        {
            if (ModelState.IsValid)
            {
                db.Datas.Add(data);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(data);
        }

        // GET: Data/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Data data = db.Datas.Find(id);
            if (data == null)
            {
                return HttpNotFound();
            }
            return View(data);
        }

        // POST: Data/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,Title,Author,Year")] Data data)
        {
            if (ModelState.IsValid)
            {
                db.Entry(data).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(data);
        }

        // GET: Data/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Data data = db.Datas.Find(id);
            if (data == null)
            {
                return HttpNotFound();
            }
            return View(data);
        }

        // POST: Data/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Data data = db.Datas.Find(id);
            db.Datas.Remove(data);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
