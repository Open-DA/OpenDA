/*************************************************************************
【文件名】                 WindowStyle.cpp
【功能模块和目的】         Windowstyle类函数实现
【开发者及日期】           彭程 2022/3/5
*************************************************************************/

#include"WindowStyle.h"

/*************************************************************************
【函数名称】       WindowStyle(Style m_style)
【函数功能】       WindowStyle类的构造函数
【参数】           Style m_style
【返回值】         无
【开发者及日期】   彭程 2022/3/5
*************************************************************************/
 WindowStyle:: WindowStyle(Style m_style){
    Status.Caption=Caption_On;
    Status.Client=Client_On;
    Status.Close=Close_On;
    Status.Edge=Edge_On;
    Status.Icon=Icon_On;
    Status.Maximize=Maximize_On;
    Status.Minimize=Minimize_On;
    Status.Resizer=Resizer_On;
  switch (m_style)
  {
  case 2:
    Status.Icon=OFF;
    Status.Maximize=OFF;
    Status.Minimize=OFF;
    Status.Resizer=OFF;
    break;
  case 3:
    Status.Resizer=OFF;
    break;
  case 4:
    Status.Caption=OFF;
    Status.Close=OFF;
    Status.Edge=OFF;
    Status.Icon=OFF;
    Status.Maximize=OFF;
    Status.Minimize=OFF;
    Status.Resizer=OFF;
    break;
  case 5:
    Status.Caption=OFF;
    Status.Edge=OFF;
    Status.Icon=OFF;
    Status.Maximize=OFF;
    Status.Minimize=OFF;
    Status.Resizer=OFF;
    break;
  case 6:
    Status.Caption=OFF;
    Status.Icon=OFF;
    Status.Maximize=OFF;
    Status.Minimize=OFF;
    break;
  default:
    break;
  }
}

 /*************************************************************************
【函数名称】       ~WindowStyle()
【函数功能】       WindowStyle类的析构函数
【参数】           无
【返回值】         无
【开发者及日期】   彭程 2022/3/5
*************************************************************************/
 WindowStyle::~ WindowStyle(){
}

 /*************************************************************************
 【函数名称】       IsTitleBarShown()
 【函数功能】       返回TitleBar的显示情况
 【参数】           无
 【返回值】         无
 【开发者及日期】   彭程 2022/3/5
 *************************************************************************/
bool WindowStyle::IsTitleBarShown(){
  return ~(~Status.Icon & ~Status.Caption & ~Status.Maximize & ~Status.Minimize & ~Status.Close) ;
}

/*************************************************************************
 【函数名称】       IsBoardShown()
 【函数功能】       返回Board的显示情况
 【参数】           无
 【返回值】         无
 【开发者及日期】   彭程 2022/3/5
 *************************************************************************/
bool WindowStyle::IsBoardShown(){
  return Status.Edge;
}

/*************************************************************************
 【函数名称】       IsClientShown()
 【函数功能】       返回Client的显示情况
 【参数】           无
 【返回值】         无
 【开发者及日期】   彭程 2022/3/5
 *************************************************************************/
bool WindowStyle::IsClientShown(){
  return Status.Client;
}

/*************************************************************************
 【函数名称】       IsIconShown()
 【函数功能】       返回Icon的显示情况
 【参数】           无
 【返回值】         无
 【开发者及日期】   彭程 2022/3/5
 *************************************************************************/
bool WindowStyle::IsIconShown(){
  return Status.Icon;
}

/*************************************************************************
 【函数名称】       IsCaptionShown()
 【函数功能】       返回Caption的显示情况
 【参数】           无
 【返回值】         无
 【开发者及日期】   彭程 2022/3/5
 *************************************************************************/
bool WindowStyle::IsCaptionShown(){
  return Status.Caption;
}

/*************************************************************************
 【函数名称】       IsMaximizeShown()
 【函数功能】       返回Maximize的显示情况
 【参数】           无
 【返回值】         无
 【开发者及日期】   彭程 2022/3/5
 *************************************************************************/
bool WindowStyle::IsMaximizeShown(){
  return Status.Maximize;
}

/*************************************************************************
 【函数名称】       IsCloseShown()
 【函数功能】       返回Close的显示情况
 【参数】           无
 【返回值】         无
 【开发者及日期】   彭程 2022/3/5
 *************************************************************************/
bool WindowStyle::IsCloseShown(){
  return Status.Close;
}

/*************************************************************************
 【函数名称】       IsEdgeShown()
 【函数功能】       返回Edge的显示情况
 【参数】           无
 【返回值】         无
 【开发者及日期】   彭程 2022/3/5
 *************************************************************************/
bool WindowStyle::IsEdgeShown(){
  return Status.Edge;
}

/*************************************************************************
 【函数名称】       IsResizerShown()
 【函数功能】       返回Resizer的显示情况
 【参数】           无
 【返回值】         无
 【开发者及日期】   彭程 2022/3/5
 *************************************************************************/
bool WindowStyle::IsResizerShown(){
  return Status.Resizer;
}


/*************************************************************************
 【函数名称】       GetStatus()
 【函数功能】       获取当前显示情况
 【参数】           无
 【返回值】         status结构体对象
 【开发者及日期】   彭程 2022/3/5
 *************************************************************************/
status WindowStyle::GetStatus(){
  return Status;
}