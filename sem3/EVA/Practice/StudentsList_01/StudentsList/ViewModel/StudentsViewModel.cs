using System.Linq;
using System.Collections.ObjectModel;
using System.Windows.Navigation;
using System.Windows;

namespace ELTE.StudentsList.ViewModel
{
    /// <summary>
    /// Hallgatók megjelenítő típusa.
    /// </summary>
    public class StudentsViewModel
    {
        /// <summary>
        /// Hallgatók gyűjteményének lekérdezése.
        /// </summary>
        public ObservableCollection<Student> Students { get; set; }
        private bool _addFerrisHasExecuted;
        public DelegateCommand AddFerrisCmd { get; set; }
        public DelegateCommand Write { get; set; }

        public StudentsViewModel()
        {
            Students = new ObservableCollection<Student>();
            _addFerrisHasExecuted = false;
            AddFerrisCmd = new DelegateCommand(
                _ =>  {
                    Students.Add(new Student { Id = 1, LastName = "Argyle", FirstName = "Felix", StudentCode = "42069UwU" });
                    _addFerrisHasExecuted = true;
                },
                _ => !_addFerrisHasExecuted
                );
            Write = new DelegateCommand(
                x => MessageBox.Show($"{x}"),
                x => x != null && x.ToString() == "Gem"
                ); 

            Students.Add(new Student { Id = 1, LastName = "Kis", FirstName = "János", StudentCode = "KIJSAAI" });
            Students.Add(new Student { Id = 2, LastName = "Nagy", FirstName = "Ferenc", StudentCode = "NAFSAAI" });
            Students.Add(new Student { Id = 3, LastName = "Huba", FirstName = "Hugó", StudentCode = "HUHSAAI" });
            Students.Add(new Student { Id = 4, LastName = "Gem", FirstName = "Géza", StudentCode = "GEGSAAI" });
            // a tulajdonságokat objektuminicializálás segítségével hozzuk létre
        }

        public string RandomStudent
        {
            get { return Students[3].LastName; }
        }
    }
}
