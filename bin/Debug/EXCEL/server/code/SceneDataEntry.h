// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     SceneDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _SCENEDATALOADER_H
#define _SCENEDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct SceneDataEntry
{
	SceneDataEntry() : id(0), type(0), minlevel(0), maxlevel(0), scriptId(0), option(0), majorCity(0), camp(0), syncRange(0), maxPlayerNum(0), reviveTime(0), recoverPercent(0), revivePosX1(0.f), revivePosY1(0.f), revivePosX2(0.f), revivePosY2(0.f), revivePosX3(0.f), revivePosY3(0.f), enterScene(0), enterX(0.f), enterY(0.f), enterZ(0.f), enterNpc(0), itemId(0), dailytimes(0), entryConfig(0), mapConfig(0), astrolabeType(0), mapGroup(0), pickupRange(0){}
	virtual ~SceneDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	ID
	**/
	UInt32	id;

	/**
	名称
	**/
	string	name;

	/**
	类型
	**/
	UInt8	type;

	/**
	最小等级
	**/
	UInt16	minlevel;

	/**
	最大等级
	**/
	UInt16	maxlevel;

	/**
	脚本id
	**/
	UInt32	scriptId;

	/**
	选项
	**/
	UInt16	option;

	/**
	主城
	**/
	UInt32	majorCity;

	/**
	阵营
	**/
	UInt8	camp;

	/**
	同步范围
	**/
	UInt32	syncRange;

	/**
	最大人数
	**/
	UInt32	maxPlayerNum;

	/**
	场景复活时间
	**/
	UInt32	reviveTime;

	/**
	场景复活恢复比
	**/
	UInt32	recoverPercent;

	/**
	复活点X1
	**/
	Real32	revivePosX1;

	/**
	复活点Z1
	**/
	Real32	revivePosY1;

	/**
	复活点X2
	**/
	Real32	revivePosX2;

	/**
	复活点Z2
	**/
	Real32	revivePosY2;

	/**
	复活点X3
	**/
	Real32	revivePosX3;

	/**
	复活点Z3
	**/
	Real32	revivePosY3;

	/**
	入口地图
	**/
	UInt16	enterScene;

	/**
	入口点X
	**/
	Real32	enterX;

	/**
	入口点Y
	**/
	Real32	enterY;

	/**
	入口点Z
	**/
	Real32	enterZ;

	/**
	入口NPC
	**/
	UInt32	enterNpc;

	/**
	消耗道具
	**/
	UInt32	itemId;

	/**
	副本次数
	**/
	UInt8	dailytimes;

	/**
	地图上怪物，出口配置
	**/
	UInt32	entryConfig;

	/**
	地图资源配置（高度图，导航）
	**/
	UInt32	mapConfig;

	/**
	星盘类型
	**/
	UInt8	astrolabeType;

	/**
	地图组
	**/
	UInt8	mapGroup;

	/**
	自动拾取范围
	**/
	UInt8	pickupRange;
}; // SceneDataEntry define end

//data visitor for the excel table
template <typename T>
class SceneDataEntryVisitor
{
public:
	SceneDataEntryVisitor(){ static_assert(std::is_base_of<SceneDataEntry, T>::value != 0, "T must be inherited from SceneDataEntry"); }
	virtual ~SceneDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class SceneDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	SceneDataLoader(){ static_assert(std::is_base_of<SceneDataEntry, T>::value != 0, "T must be inherited from SceneDataEntry"); }
	~SceneDataLoader(){ ClearData(); }

	virtual bool ParseData(T* pT)
	{
		return true;
	}

	virtual bool AfterLoad()
	{
		return true;
	}

	bool LoadData(const std::string& strPath)
	{
		ClearData();
		Avalon::XmlDocument doc(strPath);
		if(!doc.LoadFile()) return false;
		Avalon::XmlElement* pElemRoot = doc.RootElement();
		if(pElemRoot == NULL)
		{
			return false;
		}
		TiXmlElement* pDataElem = doc.FirstChildElement(pElemRoot, "Row");
		UInt32 autoIncKey = 0;
		while(pDataElem != NULL)
		{
			T* pData = new T;
			doc.GetAttribute(pDataElem, "id", pData->id);
			doc.GetAttribute(pDataElem, "name", pData->name);
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "minlevel", pData->minlevel);
			doc.GetAttribute(pDataElem, "maxlevel", pData->maxlevel);
			doc.GetAttribute(pDataElem, "scriptId", pData->scriptId);
			doc.GetAttribute(pDataElem, "option", pData->option);
			doc.GetAttribute(pDataElem, "majorCity", pData->majorCity);
			doc.GetAttribute(pDataElem, "camp", pData->camp);
			doc.GetAttribute(pDataElem, "syncRange", pData->syncRange);
			doc.GetAttribute(pDataElem, "maxPlayerNum", pData->maxPlayerNum);
			doc.GetAttribute(pDataElem, "reviveTime", pData->reviveTime);
			doc.GetAttribute(pDataElem, "recoverPercent", pData->recoverPercent);
			doc.GetAttribute(pDataElem, "revivePosX1", pData->revivePosX1);
			doc.GetAttribute(pDataElem, "revivePosY1", pData->revivePosY1);
			doc.GetAttribute(pDataElem, "revivePosX2", pData->revivePosX2);
			doc.GetAttribute(pDataElem, "revivePosY2", pData->revivePosY2);
			doc.GetAttribute(pDataElem, "revivePosX3", pData->revivePosX3);
			doc.GetAttribute(pDataElem, "revivePosY3", pData->revivePosY3);
			doc.GetAttribute(pDataElem, "enterScene", pData->enterScene);
			doc.GetAttribute(pDataElem, "enterX", pData->enterX);
			doc.GetAttribute(pDataElem, "enterY", pData->enterY);
			doc.GetAttribute(pDataElem, "enterZ", pData->enterZ);
			doc.GetAttribute(pDataElem, "enterNpc", pData->enterNpc);
			doc.GetAttribute(pDataElem, "itemId", pData->itemId);
			doc.GetAttribute(pDataElem, "dailytimes", pData->dailytimes);
			doc.GetAttribute(pDataElem, "entryConfig", pData->entryConfig);
			doc.GetAttribute(pDataElem, "mapConfig", pData->mapConfig);
			doc.GetAttribute(pDataElem, "astrolabeType", pData->astrolabeType);
			doc.GetAttribute(pDataElem, "mapGroup", pData->mapGroup);
			doc.GetAttribute(pDataElem, "pickupRange", pData->pickupRange);
			if(!ParseData(pData)) return false;
			if(pData->GetKey() != 0xFFFFFFFF)
			{
				if(!_mapData.insert(std::make_pair(pData->GetKey(), pData)).second)
				{
					delete pData;
					ClearData();
					return false;
				}
			}
			else
			{
				if(!_mapData.insert(std::make_pair(++autoIncKey, pData)).second)
					delete pData;
			}
			pDataElem = doc.NextElement(pDataElem);
		}
		return AfterLoad();
	}

	void VisitData(SceneDataEntryVisitor<T>& visitor)
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end(); ++itr)
		{
			if(!visitor(itr->second))
				return;
		}
	}

	T* FindEntry(UInt32 key)
	{
		auto itr = _mapData.find(key);
		if(itr != _mapData.end())
			return itr->second;
		return NULL;
	}

	void ClearData()
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end();++itr)
		{
			const T *p = itr->second;
			delete p;
		}
		_mapData.clear();
	}
};

#endif

