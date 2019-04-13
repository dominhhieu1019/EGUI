using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Text.RegularExpressions;

namespace Library
{
    /// <summary>
    /// Interaction logic for AddEditWindow.xaml
    /// </summary>
    public partial class AddEditWindow : Window
    {
        public static string SaveButtonName { get; set; } 
        public static string InitialTitle { get; set; }
        public AddEditWindow(string buttonName, string title = null, string author = null, string year = null)
        {
            InitializeComponent();
            SaveButtonName = buttonName;
            InitialTitle = title;
            SaveButton.Content = buttonName;
            TitleText.Text = title;
            AuthorText.Text = author;
            YearText.Text = year;
        }
        private void NumberValidationTextBox(object sender, TextCompositionEventArgs e)
        {
            Regex regex = new Regex("[^0-9]+");
            e.Handled = regex.IsMatch(e.Text);
        }
        
    }
}
