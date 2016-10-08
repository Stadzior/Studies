using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace Server
{

    public enum Status
    {
        Borrowed,
        Available    
    }

    [ServiceContract]
    public interface IServiceLibrary
    {
        List<User> Users { get; set; }
        List<Book> Books { get; set; }

        [OperationContract]
        List<Book> GetBorrowedBooksByUser(int idUser);

        [OperationContract]
        BookInfo GetBookInfo(int idBook);

        [OperationContract]
        Status BorrowBook(int idUser, int idBook);
    }
}
