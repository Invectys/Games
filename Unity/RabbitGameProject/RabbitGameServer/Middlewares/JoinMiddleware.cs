using Microsoft.AspNetCore.Http;
using RabbitGameServer.Controllers;
using RabbitGameServer.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace RabbitGameServer.Middlewares
{
    public class JoinMiddleware : Middleware
    {
        public override async Task InvokeAsync(HttpContext context)
        {
            Game game = server.GamesStorage.GetGameForJoin();
            if(game == null)
            {
                await context.Response.WriteAsync()
            }
        }
    }
}
