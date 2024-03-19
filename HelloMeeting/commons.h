#pragma once
#include <vector>
#include <QPixmap>
using namespace std;
//左侧小视频窗口的宽高
#define SMALL_VIDEO_WIDTH  300
#define SMALL_VIDEO_HEIGHT 225


#define SHARE_WINDOW_ITEM_WIDTH 200
#define SHARE_WINDOW_ITEM_HENGHT 150

struct window_share_info
{
	enum WindowType
	{
		Screen,
		Window
	};


	void *hwmd;
	std::string name;
	WindowType windowType;
	QPixmap pixmap;
};
using VecWindowShareInfo = vector<window_share_info>;