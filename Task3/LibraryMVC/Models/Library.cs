using System;
using System.Collections.Generic;
using System.Linq;
using LibraryMVC.Models;
using Microsoft.AspNetCore.Mvc;

namespace LibraryMVC.Models {
    public static class Library {
        private static int idBook = 4;
        //private static List<int> yearList = new List<int>();
        private static List<Book> bookList = new List<Book>()  {
            new Book() { Id=1, Title="Jeremy", Author="Clarkson", Year=2000},
            new Book() { Id=2, Title="James", Author="May", Year=2002},
            new Book() { Id=3, Title="Richard", Author="Hamming", Year=2010},
            new Book() { Id=4, Title="Rowan", Author="Atkinson", Year=2015}
        };
        public static List<Book> GetLibrary() {
            return bookList;
        }

        public static void AddBook(string title, string author, int year)
        {
            Book book = new Book() {Id = ++idBook, Title = title, Author = author, Year = year};
            bookList.Add(book);
            
        }

        public static void EditBook(int id, string title, string author, int year)
        {
            Book book = bookList.FirstOrDefault(x => x.Id == id);
            if (book != null)
            {
                book.Title = title;
                book.Author = author;
                book.Year = year;
            }
        }

        public static void DeleteBook(int id)
        {
            int index = bookList.FindIndex(x => x.Id == id);
            bookList.RemoveAt(index);
        }

        public static List<int> YearList => bookList.OrderBy(x => x.Year).Select(x => x.Year).Distinct().ToList();

        public static List<int> GetYearList(){
            return YearList;
        }
    }
}