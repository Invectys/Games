using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Threading.Tasks;

namespace RabbitGameServer.Models
{
    public class Game
    {
        public string Id { get;  }

        public World World { get { return _world;  }  }
        public List<Player> Players { get;}

        World _world;

        public Game(World world)
        {
            Players = new List<Player>();
            _world = world;
        }
    }
}
