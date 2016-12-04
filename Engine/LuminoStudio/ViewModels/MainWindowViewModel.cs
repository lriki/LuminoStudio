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
using Reactive.Bindings;
using System.Reactive.Linq;

namespace LuminoStudio.ViewModels
{
    public class MainWindowViewModel : ViewModel
    {

        public ReactiveCommand NewProjectCommand { get; private set; }

        public MainWindowViewModel()
        {
            NewProjectCommand = new ReactiveCommand();
            NewProjectCommand.Subscribe(_ => {
                Console.WriteLine("do");


                var vm = new ProjectCreationWindowViewModel();
                Messenger.Raise(new TransitionMessage(vm, "ProjectCreationWindow"));
                if (vm.DialogResult)
                {
                }
                Console.WriteLine(vm.DialogResult);
            });
        }

        public void Initialize()
        {
        }
    }
}
