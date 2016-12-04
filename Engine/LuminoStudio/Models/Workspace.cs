using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Livet;

namespace LuminoStudio.Models
{
    public static class Workspace
    {
        public static Project Project;

        public static void CreateProject(string name, string location)
        {
            Project = new Project(name, location, SimpleAADVGameGenre.PluginInfo.CreateGenrePreset());
        }
    }
}
