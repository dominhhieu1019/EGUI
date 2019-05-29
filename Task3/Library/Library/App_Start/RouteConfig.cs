using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;

namespace Library
{
    public class RouteConfig
    {
        public static void RegisterRoutes(RouteCollection routes)
        {
            routes.IgnoreRoute("{resource}.axd/{*pathInfo}");

            routes.MapRoute(
                name: "Default",
                url: "{controller}/{action}/{id}",
                defaults: new { controller = "Data", action = "Index", id = UrlParameter.Optional }
            );

            routes.MapRoute(
                name: "Filter",
                url: "{controller}/{action}/{titleSearch}/{authorSearch}/{yearSearch}",
                defaults: new { controller = "Data", action = "Index",
                    titleSearch = UrlParameter.Optional, authorSearch = UrlParameter.Optional, yearSearch = UrlParameter.Optional }
            );
        }
    }
}
