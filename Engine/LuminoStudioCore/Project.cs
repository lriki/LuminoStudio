using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Newtonsoft.Json;

namespace LuminoStudio
{
    [JsonObject]
    public class ProjectData
    {
        /// <summary>
        /// Name
        /// </summary>
        [JsonProperty]
        public string Name { get; set; }
    }

    public class Project
    {
        private const string ProjectFileExt = ".lnproj";

        /// <summary>
        /// Data
        /// </summary>
        public ProjectData Data { get; private set; }

        /// <summary>
        /// GenrePreset
        /// </summary>
        public GenrePreset GenrePreset { get; private set; }

        /// <summary>
        /// ProjectFileFullPath
        /// </summary>
        public string ProjectFileFullPath { get; private set; }

        /// <summary>
        /// RootDirectoryFullPath
        /// </summary>
        public string RootDirectoryFullPath { get; private set; }

        /// <summary>
        /// ResourceDirectoryFullPath
        /// </summary>
        public string ResourceDirectoryFullPath { get; private set; }

        /// <summary>
        /// 新規作成
        /// </summary>
        public Project(string name, string location, GenrePreset genrePreset)
        {
            Data = new ProjectData();
            Data.Name = name;

            RootDirectoryFullPath = location;
            ProjectFileFullPath = Path.Combine(RootDirectoryFullPath, name + ProjectFileExt);
            ResourceDirectoryFullPath = Path.Combine(RootDirectoryFullPath, "Contents");
            GenrePreset = genrePreset;
        }

        /// <summary>
        /// Save
        /// </summary>
        public void SaveProjectFile()
        {
            string jsonText = Newtonsoft.Json.JsonConvert.SerializeObject(Data, Formatting.Indented);
            File.WriteAllText(ProjectFileFullPath, jsonText);
        }

        /// <summary>
        /// Load
        /// </summary>
        /// <param name="filePath"></param>
        public void LoadProjectFile(string filePath)
        {
            string jsonText = File.ReadAllText(filePath);
            Data = JsonConvert.DeserializeObject<ProjectData>(jsonText);
        }

        /// <summary>
        /// プロジェクトフォルダ一式の作成
        /// </summary>
        public void CreateWorkDirectories()
        {
            // ルートフォルダ
            Directory.CreateDirectory(RootDirectoryFullPath);

            // リソースフォルダ
            Directory.CreateDirectory(ResourceDirectoryFullPath);

            // ジャンル固有のフォルダ
            GenrePreset.OnCreateWorkDirectories(ResourceDirectoryFullPath);
        }
    }
}
