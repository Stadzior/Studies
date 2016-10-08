using System;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace Server
{
    [DataContract]
    public class BookInfo
    {
        [DataMember]
        public Status Status { get; set; }

        [DataMember]
        public string Author { get; set; }

        [DataMember]
        public string Title { get; set; }

        [DataMember]
        public DateTime? BorrowDate { get; set; }

        [DataMember]
        public DateTime? ExpirationDate { get; set; }

        [DataMember]
        public int? IdCurrentOwner { get; set; }

        public BookInfo(string author, string title, Status status = Status.Available, DateTime? borrowDate = null,DateTime? expirationDate = null, int? idCurrentOwner = null)
        {
            Status = status;
            Author = author;
            Title = title;
            BorrowDate = borrowDate;
            ExpirationDate = expirationDate;
            IdCurrentOwner = idCurrentOwner;
        }
    }
}