using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace RabbitGameServer.Controllers
{
    public class Server
    {

        public GamesStorage GamesStorage { get; set; }

        static Server _instance;
        public static Server GetInstance()
        {
            if(_instance == null)
            {
                _instance = new Server();
            }
            return _instance;
        }


    }
}
