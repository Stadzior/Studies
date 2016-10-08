using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace Server
{

    public class ServiceLibrary : IServiceLibrary
    {
        public ServiceLibrary()
        {
            InitializeLibrary();
        }

        private DBContext.UtilsDB _dbContext = DBContext.UtilsDB.Instance;

        private void InitializeLibrary()
        {
            //Pobieranie bazy tsql
            Books = _dbContext.GetBooks();
            Users = _dbContext.GetUsers();
        }

        public List<Book> Books { get; set; }

        public List<User> Users { get; set; }

        [FaultContract(typeof(BookNotFoundException))]
        [FaultContract(typeof(BookAlreadyBorrowedException))]
        public Status BorrowBook(int idUser, int idBook)
        {

            Book book = GetBook(idBook);
            User user = GetUser(idUser);

            if (book.Info.Status == Status.Borrowed) {
                throw new FaultException<BookAlreadyBorrowedException>(new BookAlreadyBorrowedException(),"Book is already borrowed.\n");
            }
            else
            {
                book.Info.IdCurrentOwner = idUser;
                book.Info.Status = Status.Borrowed;
            }
            _dbContext.ChangeBookStatus(Books);

            return book.Info.Status;
        }

        public BookInfo GetBookInfo(int idBook)
        {
            return GetBook(idBook).Info;
        }

        public List<Book> GetBorrowedBooksByUser(int idUser)
        {
            return Books.Where((book)=>book.Info.IdCurrentOwner.Equals(idUser)).ToList();
        }

        [FaultContract(typeof(UserNotFoundException))]
        User GetUser(int idUser)
        {
            try
            {
                return Users.Where((user) => user.Id.Equals(idUser)).First();
            }
            catch (InvalidOperationException)
            {
                throw new FaultException<UserNotFoundException>(new UserNotFoundException(),"User not found.\n");
            }
        }
        [FaultContract(typeof(BookNotFoundException))]
        Book GetBook(int idBook)
        {
            try
            {
                return Books.Where((book) => book.Id.Equals(idBook)).First();
            }
            catch (InvalidOperationException)
            {
                throw new FaultException<BookNotFoundException>(new BookNotFoundException(),"Book not found.\n");
            }
        }
    }
}
