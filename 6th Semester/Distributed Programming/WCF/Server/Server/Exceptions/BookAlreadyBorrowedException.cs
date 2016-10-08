using System;
using System.Runtime.Serialization;

namespace Server
{
    [Serializable]
    internal class BookAlreadyBorrowedException : Exception
    {

        public BookAlreadyBorrowedException()
        {
        }

        public BookAlreadyBorrowedException(string message) : base(message)
        {
        }

        public BookAlreadyBorrowedException(string message, Exception innerException) : base(message, innerException)
        {
        }

        protected BookAlreadyBorrowedException(SerializationInfo info, StreamingContext context) : base(info, context)
        {
        }
    }
}