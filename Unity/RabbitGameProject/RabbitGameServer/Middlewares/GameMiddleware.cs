using Microsoft.AspNetCore.Http;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace RabbitGameServer.Middlewares
{
    public class GameMiddleware : Middleware
    {
        public override Task InvokeAsync(HttpContext context)
        {
            throw new NotImplementedException();
        }
    }
}
