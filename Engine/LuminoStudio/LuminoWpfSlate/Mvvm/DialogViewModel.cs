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

namespace LuminoWpfSlate.Mvvm
{
    public class DialogViewModel : ViewModel
    {
        /// <summary>
        /// [OK] がクリックされてダイアログを閉じた場合は true
        /// </summary>
        public bool DialogResult { get; protected set; }
        
        /// <summary>
        /// ウィンドウを閉じます。
        /// </summary>
        public virtual void Close()
        {
            SendWindowAction(WindowAction.Close);
        }

        public void OnOk()
        {
            DialogResult = true;
            Close();
        }

        public void OnCancel()
        {
            DialogResult = false;
            Close();
        }

        protected void SendWindowAction(WindowAction action)
        {
            //Messenger.Raise(new WindowActionMessage(action, "Window.WindowAction"));
            Messenger.Raise(new WindowActionMessage(WindowAction.Close, "WindowAction"));
        }
    }
}
