using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SimpleAADVGameGenre
{
    public class SimpleAADVGameGenre : LuminoStudio.GenrePreset
    {
        public override void OnCreateWorkDirectories(string resourceDirectoryFullPath)
        {
            Directory.CreateDirectory(Path.Combine(resourceDirectoryFullPath, "Audio"));
            Directory.CreateDirectory(Path.Combine(resourceDirectoryFullPath, "Map"));
            Directory.CreateDirectory(Path.Combine(resourceDirectoryFullPath, "Tileset"));
        }
    }
}
