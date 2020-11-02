using Microsoft.AspNetCore.Http;
using RabbitGameServer.Controllers;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace RabbitGameServer.Middlewares
{
    public abstract  class Middleware
    {
        protected RequestDelegate next;
        protected Server server;
        
        public Middleware(RequestDelegate next)
        {
            this.next = next;
            server = Server.GetInstance();
        }

        public abstract Task InvokeAsync(HttpContext context);
        
    }
}
