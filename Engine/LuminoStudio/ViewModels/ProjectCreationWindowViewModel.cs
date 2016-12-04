using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;

using Livet;
using Livet.Commands;
using Livet.Messaging;
using Livet.Messaging.IO;
using Livet.EventListeners;
using Livet.Messaging.Windows;

using LuminoStudio.Models;
using LuminoWpfSlate.Mvvm;
using Reactive.Bindings;
using System.Reactive.Linq;

namespace LuminoStudio.ViewModels
{
    public class ProjectCreationWindowViewModel : DialogViewModel
    {
        public ReactiveProperty<string> ProjectName { get; private set; }
        public ReactiveProperty<string> ProjectLocation { get; private set; }

        public ReactiveCommand OkCommand { get; private set; }

        public ProjectCreationWindowViewModel()
        {
            ProjectName = new ReactiveProperty<string>();
            ProjectLocation = new ReactiveProperty<string>();

            // ProjectName と ProjectLocation が入力されていれば実行可能
            OkCommand = Observable.CombineLatest(
                ProjectName, ProjectLocation,
                (m1, m2) => !string.IsNullOrEmpty(m1) && !string.IsNullOrEmpty(m2))
                .ToReactiveCommand();
            OkCommand.Subscribe(_ =>
            {
                Models.Workspace.CreateProject(ProjectName.Value, ProjectLocation.Value);
                Close(true);
            });

        }
        
    }
}
