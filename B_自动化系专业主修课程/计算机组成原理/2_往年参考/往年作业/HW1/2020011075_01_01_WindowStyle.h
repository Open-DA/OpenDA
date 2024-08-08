/*************************************************************************
【文件名】                 WindowStyle.cpp
【功能模块和目的】         Windowstyle类实现
【开发者及日期】           彭程 2022/3/5
*************************************************************************/
#ifndef WINDOWSTYLE_H
#define WINDOWSTYLE_H

/*************************************************************************
【枚举类名】         Style
【功能】             枚举各窗口风格
【开发者及日期】     彭程 2022/3/5
*************************************************************************/
enum Style{
Sizeable = 0x1,
Dialog = 0x2,
Single = 0x3,
None = 0x4,
Tool = 0x5,
SizeableTool = 0x6
};

/*************************************************************************
【枚举类名】         IsShown
【功能】             枚举各窗口元素显示情况
【开发者及日期】     彭程 2022/3/5
*************************************************************************/
enum IsShown{
  OFF = 0,
  Icon_On = 0x11,
  Caption_On = 0x21,
  Maximize_On = 0x31,
  Minimize_On = 0x41,
  Close_On = 0x51,
  Edge_On = 0x61,
  Resizer_On = 0x71,
  Client_On = 0x81
};

/*************************************************************************
【结构体名】         status
【功能】             存储窗口风格各元素显示情况
【开发者及日期】     彭程 2022/3/5
*************************************************************************/
struct status
{
  bool Icon : 1; 
  bool Caption : 1;
  bool Maximize : 1;
  bool Minimize : 1;
  bool Close : 1;
  bool Edge : 1;
  bool Resizer : 1;
  bool Client : 1;
};


/*************************************************************************
【类名】             WindowStyle
【功能】             窗口风格类，存储并查看各组成元素显示情况
【接口说明】         WindowStyle(Style m_style);
                     ~ WindowStyle();
                     status GetStatus();
                     bool IsTitleBarShown();
                     bool IsBoardShown();
                     bool IsClientShown();
                     bool IsIconShown();
                     bool IsCaptionShown();
                     bool IsMaximizeShown();
                     bool IsCloseShown();
                     bool IsEdgeShown();
                     bool IsResizerShown();
【开发者及日期】     彭程 2022/3/5
*************************************************************************/
class  WindowStyle
{
private:
  status Status;//状态结构体
public:
  WindowStyle(Style m_style);//构造函数
  ~ WindowStyle();//析构函数
  status GetStatus();//返回显示状态
  bool IsTitleBarShown();//Titlebar是否显示
  bool IsBoardShown();//Board是否显示
  bool IsClientShown();//Client是否显示
  bool IsIconShown();//Icon是否显示
  bool IsCaptionShown();//Caption是否显示
  bool IsMaximizeShown();//Maximize是否显示
  bool IsCloseShown();//Close是否显示
  bool IsEdgeShown();//Edge是否显示
  bool IsResizerShown();//Resize是否显示
};

#endif