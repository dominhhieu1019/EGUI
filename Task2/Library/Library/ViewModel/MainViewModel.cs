using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Data;
using System.Windows.Input;
using Library.Model;

namespace Library.ViewModel
{
    public class MainViewModel : BaseViewModel
    {
        private static ObservableCollection<Data> _List;
        public static ObservableCollection<Data> List { get => _List; set { _List = value; NotifyStaticPropertyChanged(); } }

        private static ObservableCollection<String> _YearList;
        public static ObservableCollection<String> YearList { get => _YearList; set { _YearList = value; NotifyStaticPropertyChanged(); } }

        //private List<string> selectedList = new List<string>();
        
        private Data _SelectedItem;
        public Data SelectedItem
        {
            get => _SelectedItem;
            set
            {
                _SelectedItem = value;
                //selectedList.Add(SelectedItem.Title);
                OnPropertyChanged();
            }
        }

       /* private bool _IsSelected;
        public bool IsSelected
        {
            get => _IsSelected;
            set
            {
                _IsSelected = value;

            }
        }*/

        

        private string _TitleFilter;
        public string TitleFilter { get => _TitleFilter; set { _TitleFilter = value; OnPropertyChanged(); } }

        private string _AuthorFilter;
        public string AuthorFilter { get => _AuthorFilter; set { _AuthorFilter = value; OnPropertyChanged(); }  }

        private string _YearFilter;
        public string YearFilter { get => _YearFilter; set { _YearFilter = value; OnPropertyChanged();  } }

        public ICommand FilterCommand { get; set; }
        public ICommand CancelCommand { get; set; }

        public ICommand AddCommand { get; set; }
        public ICommand EditCommand { get; set; }

        public ICommand DeleteCommand { get; set; }
        public MainViewModel()
        {
            List = new ObservableCollection<Data>(DataProvider.Ins.DB.Datas);
            YearList = new ObservableCollection<String>();
            YearList.Add("");
            foreach (Data data in List)
                if(!YearList.Any(p => p == data.Year))
                    YearList.Add(data.Year);
            YearList = new ObservableCollection<string>(YearList.OrderBy(i => i));


            FilterCommand = new RelayCommand<object>((p) =>
            {
                return true;
            }, (p) =>
            {
                Filter();
               // selectedList.Clear();
            }
            );

            CancelCommand = new RelayCommand<object>((p) =>
            {
                return true;
            }, (p) =>
            {
                TitleFilter = "";
                AuthorFilter = "";
                YearFilter = "";
                CollectionViewSource.GetDefaultView(List).Refresh();
                //selectedList.Clear();
            }
            );

            AddCommand = new RelayCommand<object>((p) => { return true; }, (p) => { AddEditWindow wd = new AddEditWindow("Add"); wd.ShowDialog(); Filter(); });
            EditCommand = new RelayCommand<object>((p) => { return true; }, (p) =>
            {
                AddEditWindow wd = new AddEditWindow("Save", SelectedItem.Title, SelectedItem.Author, SelectedItem.Year); wd.ShowDialog();
                Filter();
                //selectedList.Clear();
            });

            DeleteCommand = new RelayCommand<object>((p) =>
            {
                return true;
            }, (p) =>
            {
                /*foreach(var item in selectedList)
                {
                    var ListData = MainViewModel.List.FirstOrDefault(x => x.Title == item);
                    if (ListData != null)
                        MainViewModel.List.Remove(ListData);
                    var Data = DataProvider.Ins.DB.Datas.Where(x => x.Title == item).SingleOrDefault();
                    if (Data != null)
                        DataProvider.Ins.DB.Datas.Remove(Data);
                }
                selectedList.Clear();*/
                var Data = DataProvider.Ins.DB.Datas.FirstOrDefault(x => x.Title == SelectedItem.Title);
                if (Data != null)
                    DataProvider.Ins.DB.Datas.Remove(Data);
                var ListData = MainViewModel.List.FirstOrDefault(x => x.Title == SelectedItem.Title);
                if (ListData != null)
                    MainViewModel.List.Remove(ListData);
            });
        }
        private void Filter()
        {
            CollectionViewSource.GetDefaultView(List).Refresh();
            CollectionView view = (CollectionView)CollectionViewSource.GetDefaultView(List);
            view.Filter = BookFilter;
        }
        private bool BookFilter(object item)
        {
            return ((String.IsNullOrEmpty(TitleFilter) || (item as Data).Title.Contains(TitleFilter))
                && (String.IsNullOrEmpty(AuthorFilter) || (item as Data).Author.Contains(AuthorFilter))
                && (String.IsNullOrEmpty(YearFilter) || (item as Data).Year.Contains(YearFilter)));
        }
    }
}
