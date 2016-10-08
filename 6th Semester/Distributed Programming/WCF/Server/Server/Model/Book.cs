using System;
using System.Runtime.Serialization;

namespace Server
{
    [DataContract]
    public class Book
    {
        [DataMember]
        public int Id { get; set; }

        [DataMember]
        public BookInfo Info { get; set; }

        public Book(int id,string author,string title,int status,DateTime borrowDate, DateTime expirationDate, int idCurrentOwner)
        {
            Id = id;
            Info = new BookInfo(author,title,(Status)status,borrowDate,expirationDate,idCurrentOwner);
        }

        public Book(int id,BookInfo info)
        {
            Id = id;
            Info = info;
        }
    }
}