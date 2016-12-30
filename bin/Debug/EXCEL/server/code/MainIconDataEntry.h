// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     MainIconDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _MAINICONDATALOADER_H
#define _MAINICONDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct MainIconDataEntry
{
	MainIconDataEntry() : id(0), type(0), index(0), display(0), iconid(0), layoutid(0){}
	virtual ~MainIconDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	主键
	**/
	UInt16	id;

	/**
	标识
	**/
	string	data;

	/**
	说明
	**/
	string	descript;

	/**
	类型
	**/
	UInt16	type;

	/**
	引用
	**/
	UInt16	index;

	/**
	位置
	**/
	UInt16	display;

	/**
	图标
	**/
	UInt16	iconid;

	/**
	层
	**/
	UInt16	layoutid;
}; // MainIconDataEntry define end

//data visitor for the excel table
template <typename T>
class MainIconDataEntryVisitor
{
public:
	MainIconDataEntryVisitor(){ static_assert(std::is_base_of<MainIconDataEntry, T>::value != 0, "T must be inherited from MainIconDataEntry"); }
	virtual ~MainIconDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class MainIconDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	MainIconDataLoader(){ static_assert(std::is_base_of<MainIconDataEntry, T>::value != 0, "T must be inherited from MainIconDataEntry"); }
	~MainIconDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "data", pData->data);
			doc.GetAttribute(pDataElem, "descript", pData->descript);
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "index", pData->index);
			doc.GetAttribute(pDataElem, "display", pData->display);
			doc.GetAttribute(pDataElem, "iconid", pData->iconid);
			doc.GetAttribute(pDataElem, "layoutid", pData->layoutid);
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

	void VisitData(MainIconDataEntryVisitor<T>& visitor)
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

