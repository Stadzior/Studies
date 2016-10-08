using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;

namespace Server.DBContext
{
    public class UtilsDB
    {
        private UtilsDB() {

        }

        private static UtilsDB _instance;

        public static UtilsDB Instance
        {
            get
            {
                if (_instance == null)
                {
                    _instance = new UtilsDB();
                }
                return _instance;
            }
        }


        private  SqlConnection _connection = new SqlConnection("Server=EKOBIOBUD;Database=Library;Trusted_Connection=Yes");

        private DataTable GetTableFromProcedure(string procedureName,List<SqlParameter> parameters = null)
        {
            SqlCommand command = new SqlCommand();
            command.Connection = _connection;
            command.CommandType = CommandType.StoredProcedure;
            command.CommandText = "dbo." + procedureName;
            if (parameters != null)
            {
                foreach (SqlParameter parameter in parameters)
                {
                    command.Parameters.Add(parameter);
                }
            }
            SqlDataAdapter adapter = new SqlDataAdapter(command);
            DataTable data = new DataTable();
            adapter.Fill(data);

            return data;
        }

        private void ExecuteProcedureWithoutOutput(string procedureName, List<SqlParameter> parameters = null)
        {
            SqlCommand command = new SqlCommand();
            command.Connection = _connection;
            command.CommandType = CommandType.StoredProcedure;
            command.CommandText = "dbo." + procedureName;
            if (parameters != null)
            {
                foreach (SqlParameter parameter in parameters)
                {
                    command.Parameters.Add(parameter);
                }
            }

            if(_connection.State == ConnectionState.Closed)
            {
                _connection.Open();
            }
            command.ExecuteNonQuery();

            if (_connection.State == ConnectionState.Open)
            {
                _connection.Close();
            }
        }


        public List<User> GetUsers()
        {
            List<User> users = new List<User>();
            DataTable data = GetTableFromProcedure("GetUsers");
            foreach (DataRow row in data.Rows)
            {
                User user = new User((int)row["IdUser"], (string)row["UserName"]);
                users.Add(user);
            }
            return users;
        }

        public List<Book> GetBooks()
        {
            List<Book> books = new List<Book>();
            DataTable data = GetTableFromProcedure("GetBooks");
            foreach (DataRow row in data.Rows)
            {
                BookInfo info = new BookInfo(
                    (string)row["Author"],
                    (string)row["Title"],
                    (Status)row["Status"],
                    row["BorrowDate"] == DBNull.Value? null : (DateTime?)row["BorrowDate"],
                    row["ExpirationDate"] == DBNull.Value ? null : (DateTime?)row["ExpirationDate"],
                    row["IdCurrentOwner"] == DBNull.Value ? null : (int?)row["IdCurrentOwner"]);
                Book book = new Book((int)row["IdBook"], info);
                books.Add(book);
            }
            return books;
        }

        public void ChangeBookStatus(List<Book> books)
        {
            List<SqlParameter> parameters = new List<SqlParameter>();
            foreach (Book book in books)
            {
                parameters.Add(new SqlParameter("IdBook", book.Id));
                parameters.Add(new SqlParameter("Status", book.Info.Status));
                if (book.Info.IdCurrentOwner == null)
                {
                    var param = new SqlParameter("IdCurrentOwner", SqlDbType.Int);
                    param.Value = DBNull.Value;
                    parameters.Add(param);
                }
                else
                {
                    parameters.Add(new SqlParameter("IdCurrentOwner", book.Info.IdCurrentOwner));
                }  
                ExecuteProcedureWithoutOutput("ChangeBookStatus", parameters);
                parameters.Clear();
            }
        }
    }
}
