using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using Livet.Behaviors;

namespace LuminoWpfSlate.Controls
{
    public class CallMethodButton : Button
    {
        private readonly MethodBinder _binder = new MethodBinder();

        #region MethodName 依存関係プロパティ

        public string MethodName
        {
            get { return (string)this.GetValue(MethodNameProperty); }
            set { this.SetValue(MethodNameProperty, value); }
        }
        public static readonly DependencyProperty MethodNameProperty =
            DependencyProperty.Register(nameof(MethodName), typeof(string), typeof(CallMethodButton), new UIPropertyMetadata(null));

        #endregion

        protected override void OnClick()
        {
            base.OnClick();

            if (string.IsNullOrEmpty(this.MethodName)) return;

            var target = this.DataContext;
            if (target == null) return;

            _binder.Invoke(target, this.MethodName);
        }
    }
}
