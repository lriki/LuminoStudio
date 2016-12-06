using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LuminoStudio.ViewModels.Panes
{
    /// <summary>
    /// [リソースマネージャー] Pane の ViewModel
    /// </summary>
    class ResourceManagerPaneViewModel : PaneViewModelBase
    {
        #region Title Property
        public override string Title
        {
            get { return "出力"; }
        }
        #endregion

        #region ContentId Property
        public override string ContentId
        {
            get { return "ResourceManagerPaneViewModel"; }
        }
        #endregion
    }
}
