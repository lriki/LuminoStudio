using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleAADVGameGenre
{
    public static class PluginInfo
    {
        public static int Version = 1;
        public static string FriendlyName = "Example Plugin";
        public static string FriendlyVersion = "1.0";
        public static string Description = "example";

        public static LuminoStudio.GenrePreset CreateGenrePreset()
        {
            return new SimpleAADVGameGenre();
        }
    }
}
