using System.Collections.Generic;
using System.Runtime.Serialization;

namespace Server
{
    [DataContract]
    public class User
    {
        [DataMember]
        public int Id { get; set; }

        [DataMember]
        public string Username { get; set; }

        public User(int id,string username)
        {
            Id = id;
            Username = username;
        }
    }
}