// WndDll.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "WndDll.h"

#include "DrawButton.h"
#include "DrawEdit.h"
#include "DrawDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CWndDllApp

BEGIN_MESSAGE_MAP(CWndDllApp, CWinApp)
	//{{AFX_MSG_MAP(CWndDllApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWndDllApp construction

CWndDllApp::CWndDllApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CWndDllApp object

CWndDllApp theApp;
HHOOK  hWndHook ;
HINSTANCE hMod = NULL;




LRESULT __stdcall ButtonWindowProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	CPoint pt;
	CDrawButton *pButton=(CDrawButton*)GetWindowLong(hWnd,GWL_USERDATA);
	switch(Msg)
	{
		case WM_LBUTTONDBLCLK://屏蔽双击事件
			{
				return TRUE;
			}
		case WM_PAINT:
			{
				if(pButton->m_Style>0)
					return pButton->OnPaint(hWnd);
				else
					return CallWindowProc(pButton->m_OldProc,hWnd,Msg,wParam,lParam);
			}
		case WM_LBUTTONDOWN:
			{
				pt.x=LOWORD(lParam);
				pt.y=HIWORD(lParam);
				if(pButton->m_Style>0)
					return pButton->OnLButtonDown(hWnd,0,pt);
				else
					return CallWindowProc(pButton->m_OldProc,hWnd,Msg,wParam,lParam);
			}
		case WM_LBUTTONUP:
			{
				pt.x = LOWORD(lParam);
				pt.y = HIWORD(lParam);
				if (pButton->m_Style>0)
					return pButton->OnLButtonUp( hWnd, 0,pt );
				else
					return  CallWindowProc(pButton->m_OldProc, hWnd,Msg,wParam,lParam);
			}
		case WM_MOUSEMOVE:
			{

				pt.x = LOWORD(lParam);
				pt.y = HIWORD(lParam);
				if (pButton->m_Style>0)
					return pButton->OnMouseMove(hWnd,0, pt);
				else
					return  CallWindowProc(pButton->m_OldProc, hWnd,Msg,wParam,lParam);
			}
		case WM_DESTROY:
			{
				WNDPROC procOld=pButton->m_OldProc;
				SetWindowLong(hWnd,GWL_WNDPROC,(long)procOld);

				CWnd* pWnd=::CWnd::FromHandle(hWnd);
				if(pWnd)
					pWnd->Detach();
				pButton->m_Flag=1;
				return 1;
			}
		default:
			break;
	}
	return  CallWindowProc(pButton->m_OldProc, hWnd,Msg,wParam,lParam);
}




/*********************************************
* LRESULT __stdcall DialogWindowProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)
* 功能：为对话框添加一个自定义的窗口过程，截取WM_PAINT,WM_NCACTIVATE,,
		WM_MOUSEMOVE,WM_NCMOUSEMOVE,WM_NCLBUTTONDOWN,WM_NCPAINT,WM_SIZE等窗口
		消息
* 返回值：
**********************************************/

LRESULT __stdcall DialogWindowProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	CDrawDialog* pDlg=(CDrawDialog*)GetWindowLong(hWnd,GWL_USERDATA);
	switch(Msg)
	{
	case WM_PAINT:
		{
			pDlg->OnPaint(hWnd);			//绘制对话框
			::InvalidateRect(hWnd,NULL,true);//更新整个窗口
			break;
		}
	case WM_NCACTIVATE:
		{
			pDlg->OnNcActivate(hWnd,wParam);
			::InvalidateRect(hWnd,NULL,true);
			break;
		}
	case WM_MOUSEMOVE:
		{
			CPoint pt;
			pt.x=LOWORD(lParam);
			pt.y=HIWORD(lParam);
			//调用CDrawDialog类的OnMouseMove方法
			pDlg->OnMouseMove(hWnd,wParam,pt);
	
			break;
		}
	case WM_NCMOUSEMOVE:
		{
			CPoint pt;
			pt.x=LOWORD(lParam);
			pt.y=HIWORD(lParam);
			//调用CDrawDialog类的OnMouseMove方法
			pDlg->OnNcMouseMove(hWnd,wParam,pt);
			break;
		}
	case WM_NCLBUTTONDOWN:
		{
			CPoint pt;
			pt.x=(int)(short)LOWORD(lParam);
			pt.y=(int)(short)HIWORD(lParam);
			pDlg->OnNcLButtonDown(hWnd,wParam,pt);
			break;
		}
	case WM_NCPAINT:
		{
			pDlg->OnNcPaint(hWnd);
			::InvalidateRect(hWnd,NULL,true);
			pDlg->OnPaint(hWnd);
			break;
		}
	case WM_SIZE:
		{
			int nCX=LOWORD(lParam);
			int nCY=HIWORD(lParam);
			pDlg->OnSize(hWnd,wParam,nCX,nCY);
			::InvalidateRect(hWnd,NULL,true);
			break;
		}
	case WM_CTLCOLORDLG:
		{

			if(pDlg->m_bFlushBk)//避免闪烁
			{
				pDlg->m_bFlushBk=FALSE;
				pDlg->OnCtlColor(hWnd);
				::InvalidateRect(hWnd,NULL,true);
				break;
			}
		}
	default:
		{
			//调用对话框默认的窗口过程
			return CallWindowProc(pDlg->m_OldProc,hWnd,Msg,wParam,lParam);
		}

	}
	//继续向目标窗口传递消息
		return CallWindowProc(pDlg->m_OldProc,hWnd,Msg,wParam,lParam);

}





LRESULT __stdcall EditWindowProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParem)
{
	CPoint pt;
	//获取编辑框控件关联的数据结构
	CDrawEdit* pEdit=(CDrawEdit*)GetWindowLong(hWnd,GWL_USERDATA);
	switch(Msg)
	{
	case WM_PAINT:
		{
			//调用CDrawEdit的CtlColor方法
			pEdit->CtlColor(hWnd,::GetDC(hWnd),0);//=0,CTLCOLOR_MSGBOX
			break;
		}
	case WM_DESTROY:
		{
			WNDPROC procOld=pEdit->m_OldProc;//获取编辑框原来的窗口过程
			//恢复原来的窗口函数
			SetWindowLong(hWnd,GWL_WNDPROC,(LONG)procOld);
			CWnd* pWnd=::CWnd::FromHandle(hWnd);//将按钮对象与句柄分离
			if(pWnd)
				pWnd->Detach();		//分离窗口句柄
			pEdit->m_Flag=1;		//设置释放控件标记
			return 1;
		}
	default:
		break;
	}
	//继续向窗口传递消息
	return CallWindowProc(pEdit->m_OldProc,hWnd,Msg,wParam,lParem);

}


/****************************************************************
* LRESULT CALLBACK HOOKProc(int nCode,WPARAM wParam,LPARAM lParam)
* 定义钩子函数
* 参数：请参阅MSDN
******************************************************************/
LRESULT CALLBACK HOOKProc(int nCode,WPARAM wParam,LPARAM lParam)
{
	PCWPSTRUCT wc=(PCWPSTRUCT)lParam;
	HWND hWnd=wc->hwnd;
	if(hWnd)
	{
		char ClassName[MAX_PATH]=_T("");
		GetClassName(hWnd,ClassName,MAX_PATH);
		CWnd* pWnd=CWnd::FromHandle(hWnd);

		/*
		当按钮控件没有修改窗口过程时，修改按钮的窗口过程，并
		为按钮关联一个CDrawButton对象。当按钮控件需要释放时（m_Flag=1)，
		恢复按钮的窗口过程，释放关联的CDrawButton对象
		*/
		if(strcmp(ClassName,_T("Button"))==0)//修改按钮的窗口函数
		{
			CWnd* pWnd=CWnd::FromHandle(hWnd);
			if(pWnd->GetStyle()&BS_RADIOBUTTON||
				pWnd->GetStyle()&BS_CHECKBOX)
			{
				return 1;
			}
			WNDPROC WndProc;
			WndProc=(WNDPROC)GetWindowLong(hWnd,GWL_WNDPROC);
			//获取按钮关联的CDrawButton对象
			CDrawButton* pButton=(CDrawButton*)GetWindowLong(hWnd,GWL_USERDATA);
			if(pButton!=NULL&&pButton->m_Flag==1)//是否释放按钮
			{
				SetWindowLong(hWnd,GWL_USERDATA,0);//设置按钮关联数据为0
				//设置按钮原来的窗口过程
				SetWindowLong(hWnd,GWL_WNDPROC,(LONG)pButton->m_OldProc);
				pButton->m_OldProc=NULL;
				delete pButton;		//释放按钮关联的数据
			}
			else if(pButton==NULL)
			{
				if(WndProc!=ButtonWindowProc)
				{
					pButton=new CDrawButton;	//构建CDrawButton对象
					pButton->m_OldProc=WndProc;	//记录原来的窗口过程
					//为按钮关联一个CDrawButton对象
					SetWindowLong(hWnd,GWL_USERDATA,(LONG)pButton);
					//修改按钮的窗口过程
					WndProc=(WNDPROC)SetWindowLong(hWnd,GWL_WNDPROC,(LONG)ButtonWindowProc);//返回的是原来的值

				}
			}
		}
		/*
		当编辑框没有修改窗口过程时，修改编辑框的窗口过程，并为
		编辑框关联一个CDrawEdit对象，当编辑框控件需要释放时(m_Flag=1),
		恢复编辑框的窗口过程，并释放关联的CDrawEdit对象
		*/
		else if(strcmp(ClassName,_T("Edit"))==0)
		{
			CWnd* pWnd=CWnd::FromHandle(hWnd);
			pWnd->ModifyStyleEx(WS_EX_CLIENTEDGE,0,0);//取消编辑框的边框
			WNDPROC WndProc;		//定义一个窗口过程
			//获取编辑框原来的窗口过程
			WndProc=(WNDPROC)GetWindowLong(hWnd,GWL_WNDPROC);
			//获取编辑框关联的CDrawEdit对象
			CDrawEdit* pEdit=(CDrawEdit*)GetWindowLong(hWnd,GWL_USERDATA);
			if(pEdit!=NULL&&pEdit->m_Flag==1)//是否释放编辑框
			{
				SetWindowLong(hWnd,GWL_USERDATA,0);//设置编辑框关联数据为0
				//设置编辑框原来的窗口过程
				SetWindowLong(hWnd,GWL_WNDPROC,(LONG)pEdit->m_OldProc);
				pEdit->m_OldProc=NULL;
				delete pEdit;		//释放编辑框关联的数据
			}
			else if(pEdit==NULL)	//如果编辑框没有关联CDrawEdit对象
			{
				if(WndProc!=EditWindowProc)
				{
					pEdit=new CDrawEdit();
					pEdit->m_OldProc=WndProc;		//记录原来的窗口过程
					//为编辑框关联一个CDrawEdit对象
					SetWindowLong(hWnd,GWL_USERDATA,(LONG)pEdit);
					//修改编辑框的窗口过程
					WndProc=(WNDPROC)SetWindowLong(hWnd,GWL_WNDPROC,(LONG)EditWindowProc);
				}
			}
		}
		/*
		当对话框没有修改窗口过程时，修改对话框的窗口过程，并为对话框关联一个
		CDrawDialog对象，当对话框需要释放时(m_Flag=1)，恢复对话框的窗口过程，并释放
		关联的CDrawDialog对象
		*/
		else if(strcmp(ClassName,_T("#32770"))==0)	//vc程序默认对话框的类名为#32770
		{
			//DS_ABSALIGN - 对话框的坐标为屏幕坐标(缺省为客户区坐标)
			if(pWnd->GetStyle()&DS_ABSALIGN)	//过滤掉消息对话框
				return 0;
			WNDPROC WndProc;
			WndProc=(WNDPROC)GetWindowLong(hWnd,GWL_WNDPROC);
			pWnd->ModifyStyle(WS_SYSMENU,0,0);	//去掉对话框的标题栏按钮
			//获取对话框的关联数据
			CDrawDialog* pDlg=(CDrawDialog*)GetWindowLong(hWnd,GWL_USERDATA);
			static BOOL bClose=FALSE;
			static HWND hDialog=NULL;	//记录应用程序主窗口的句柄
			if(hDialog==NULL)
			{
				hDialog=hWnd;
			}
			//释放对话框
			if(wc->message==WM_NCDESTROY&&pDlg!=NULL&&bClose==FALSE)
			{
				//恢复对话框原来的窗口过程
				SetWindowLong(hWnd,GWL_WNDPROC,(LONG)pDlg->m_OldProc);
				delete pDlg;	//释放对话框
				if(hDialog==hWnd)//防止在主窗口关闭时执行气候的else if语句
				{
					bClose=TRUE;
				}
			}
			else if(pDlg==NULL&&bClose==FALSE)//还没有为对话框关联数据
			{
				if(WndProc!=DialogWindowProc)//还没有修改对话框的窗口过程
				{
					pDlg=new CDrawDialog();
					SetWindowLong(hWnd,GWL_USERDATA,(LONG)pDlg);
					pDlg->m_OldProc=(WNDPROC)SetWindowLong(hWnd,
						GWL_WNDPROC,(LONG)DialogWindowProc);
				}
			}
		}

	}
	return CallNextHookEx(hWndHook,nCode,wParam,lParam);
}




/*******************************************
* LRESULT __stdcall DialogWindowProc(HWND hWnd,UINT Msg,WPAREM wParam,LPARAM lParam)
* 功能：安装钩子函数
*******************************************/
BOOL __stdcall RunHook(HMODULE hModule,DWORD dwThreadID)
{
	hWndHook=SetWindowsHookEx(
		WH_CALLWNDPROC,(HOOKPROC)HOOKProc,hMod,dwThreadID);
	return TRUE;
}



/***************************
* BOOL __stdcall StopHook()
* 功能：卸载钩子
* 返回值：是否卸载成功
*****************************/
BOOL __stdcall StopHook()
{
	UnhookWindowsHookEx(hWndHook);
	return TRUE;
}
