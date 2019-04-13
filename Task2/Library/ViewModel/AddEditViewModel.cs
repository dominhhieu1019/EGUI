using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using System.Windows;
using Library.Model;
using System.Collections.ObjectModel;

namespace Library.ViewModel
{
    public class AddEditViewModel : BaseViewModel
    {
        private string _Title;
        public string Title { get => _Title; set { _Title = value; OnPropertyChanged(); } }

        private string _Author;
        public string Author { get => _Author; set { _Author = value; OnPropertyChanged(); } }

        private string _Year;
        public string Year { get => _Year; set { _Year = value; OnPropertyChanged(); } }

        public ICommand SaveCommand { get; set; }


        public AddEditViewModel()
        {
            SaveCommand = new RelayCommand<Window>((p) =>
            {
                if (String.IsNullOrEmpty(Title) || String.IsNullOrEmpty(Author) || String.IsNullOrEmpty(Year)
                        || int.Parse(Year) <= 0 || int.Parse(Year) > DateTime.Now.Year)
                       return false;

                var titleList = DataProvider.Ins.DB.Datas.Where(x => x.Title == Title);
                if ((AddEditWindow.SaveButtonName == "Add") && (titleList == null || titleList.Count() != 0))
                    return false;

                return true;
            }, (p) =>
            {
                if (AddEditWindow.SaveButtonName == "Add")
                {
                    var Data = new Data() { Title = Title, Author = Author, Year = Year };
                    DataProvider.Ins.DB.Datas.Add(Data);
                    MainViewModel.List.Add(Data);
                }
                else
                {
                    var ListData = MainViewModel.List.FirstOrDefault(x => x.Title == AddEditWindow.InitialTitle);
                    ListData.Title = Title;
                    ListData.Author = Author;
                    ListData.Year = Year;
                    var Data = DataProvider.Ins.DB.Datas.Where(x => x.Title == AddEditWindow.InitialTitle).SingleOrDefault();
                    Data.Title = Title;
                    Data.Author = Author;
                    Data.Year = Year;
                }
               
                DataProvider.Ins.DB.SaveChanges();
                foreach (Window window in Application.Current.Windows)
                {
                    if (window is AddEditWindow)
                    {
                        window.Close();
                        break;
                    }
                }

                if (!MainViewModel.YearList.Any(i => i == Year))
                {
                    MainViewModel.YearList.Add(Year);
                    MainViewModel.YearList = new ObservableCollection<string>(MainViewModel.YearList.OrderBy(i => i));
                }
                    
            }); 
        }
        
    }
}
