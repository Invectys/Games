using RabbitGameServer.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace RabbitGameServer.Controllers
{
    public class GamesStorage
    {

        List<Game> _games = new List<Game>();

        public Game GetGame(string id)
        {
            Game game = _games.First(g => g.Id == id);
            return game;
        }

        public Game GetGameForJoin()
        {
            return _games[0];
        }

        Game CreateGame()
        {
            Game game = new Game();
            _games.Add(game);
            return game;
        }
    }
}
