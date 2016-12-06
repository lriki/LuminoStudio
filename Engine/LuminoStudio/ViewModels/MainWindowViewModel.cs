using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;
using System.Collections.ObjectModel;

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
        #region DockingDocumentViewModels 変更通知プロパティ
        private ObservableCollection<ViewModel> _DockingDocumentViewModels;
        /// <summary>
        /// ドッキングドキュメントの ViewModel のリスト
        /// </summary>
        public ObservableCollection<ViewModel> DockingDocumentViewModels
        {
            get { return _DockingDocumentViewModels; }
            set
            {
                if (_DockingDocumentViewModels == value)
                    return;
                _DockingDocumentViewModels = value;
                RaisePropertyChanged(() => DockingDocumentViewModels);
            }
        }
        #endregion

        #region DockingPaneViewModels 変更通知プロパティ
        private ObservableCollection<ViewModel> _DockingPaneViewModels;
        /// <summary>
        /// ドッキングペインの ViewModel のリスト
        /// </summary>
        public ObservableCollection<ViewModel> DockingPaneViewModels
        {
            get { return _DockingPaneViewModels; }
            set
            {
                if (_DockingPaneViewModels == value)
                    return;
                _DockingPaneViewModels = value;
                RaisePropertyChanged(() => DockingPaneViewModels);
            }
        }
        #endregion

        public ReactiveCommand NewProjectCommand { get; private set; }

        /// <summary>
        /// コンストラクタ
        /// </summary>
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


            DockingDocumentViewModels = new ObservableCollection<ViewModel>();
            DockingDocumentViewModels.Add(new ViewModels.Documents.ProjectSettingDocumentViewModel());

            DockingPaneViewModels = new ObservableCollection<ViewModel>();
            DockingPaneViewModels.Add(new ViewModels.Panes.OutputPaneViewModel());
            DockingPaneViewModels.Add(new ViewModels.Panes.ResourceManagerPaneViewModel());
        }

        public void Initialize()
        {
        }
    }
}
