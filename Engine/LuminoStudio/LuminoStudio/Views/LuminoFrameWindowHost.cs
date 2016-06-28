using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Forms;
using System.Windows.Forms.Integration;
using System.Windows.Media;

namespace LuminoStudio.Views
{
    class LuminoFrameWindowControl : System.Windows.Forms.UserControl
    {
        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);

            this.SetStyle(ControlStyles.Opaque, true);
            this.SetStyle(ControlStyles.ResizeRedraw, true);
        }
    }

    class LuminoFrameWindowHost : WindowsFormsHost
    {
        public LuminoFrameWindowControl _wfControl;
        public Lumino.UINativeHostWindow _uiNativeHostWindow;

        public LuminoFrameWindowHost()
        {
            Loaded += LuminoFrameWindowHost_Loaded;
            Unloaded += LuminoFrameWindowHost_Closed;

            _wfControl = new LuminoFrameWindowControl();
            _wfControl.BackColor = System.Drawing.Color.Brown;
            //_wfControl.Paint += PaintEventHandler;
            Child = _wfControl;

        }
        
        private void LuminoFrameWindowHost_Loaded(object sender, RoutedEventArgs e)
        {
            _uiNativeHostWindow = new Lumino.UINativeHostWindow(_wfControl.Handle);
            //HwndSource source = (HwndSource)HwndSource.FromVisual(this);

            //Lumino.Config.SetUserWindowHandle(source.Handle);
            //Lumino.Engine.Initialize();

            //IWbemLocator::ConnectServer

            RenderScene();
            //Lumino.Engine.UpdateFrame();
        }

        private void LuminoFrameWindowHost_Closed(object sender, EventArgs e)
        {
            //Lumino.Engine.Terminate();
        }

        void PaintEventHandler(object sender, PaintEventArgs e)
        {
            //Lumino.Engine.UpdateFrame();
        }

        protected override void OnRender(DrawingContext drawingContext)
        {
            base.OnRender(drawingContext);
        }

        private void RenderScene()
        {
            _uiNativeHostWindow.Render();

        }
    }
}
