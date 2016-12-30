// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ComposeDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _COMPOSEDATALOADER_H
#define _COMPOSEDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ComposeDataEntry
{
	ComposeDataEntry() : itemid(0), type(0), level(0), rat(0), num(0), falitemid(0), falnum(0), bind(0), needmat1(0), num1(0), needmat2(0), num2(0), needmat3(0), num3(0), needgold(0){}
	virtual ~ComposeDataEntry(){ }
	virtual UInt32 GetKey() const { return itemid; }
	/**
	合成ID
	**/
	UInt32	itemid;

	/**
	分类
	**/
	UInt8	type;

	/**
	合成需要玩家等级
	**/
	UInt16	level;

	/**
	成功概率
	**/
	UInt16	rat;

	/**
	成功道具数量
	**/
	UInt8	num;

	/**
	失败生成道具
	**/
	UInt32	falitemid;

	/**
	失败道具数量
	**/
	UInt8	falnum;

	/**
	是否绑定
	**/
	UInt8	bind;

	/**
	原料1
	**/
	UInt32	needmat1;

	/**
	数量1
	**/
	UInt16	num1;

	/**
	原料2
	**/
	UInt32	needmat2;

	/**
	数量2
	**/
	UInt16	num2;

	/**
	原料3
	**/
	UInt32	needmat3;

	/**
	数量3
	**/
	UInt16	num3;

	/**
	需要金钱数量
	**/
	UInt32	needgold;
}; // ComposeDataEntry define end

//data visitor for the excel table
template <typename T>
class ComposeDataEntryVisitor
{
public:
	ComposeDataEntryVisitor(){ static_assert(std::is_base_of<ComposeDataEntry, T>::value != 0, "T must be inherited from ComposeDataEntry"); }
	virtual ~ComposeDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ComposeDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ComposeDataLoader(){ static_assert(std::is_base_of<ComposeDataEntry, T>::value != 0, "T must be inherited from ComposeDataEntry"); }
	~ComposeDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "itemid", pData->itemid);
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "level", pData->level);
			doc.GetAttribute(pDataElem, "rat", pData->rat);
			doc.GetAttribute(pDataElem, "num", pData->num);
			doc.GetAttribute(pDataElem, "falitemid", pData->falitemid);
			doc.GetAttribute(pDataElem, "falnum", pData->falnum);
			doc.GetAttribute(pDataElem, "bind", pData->bind);
			doc.GetAttribute(pDataElem, "needmat1", pData->needmat1);
			doc.GetAttribute(pDataElem, "num1", pData->num1);
			doc.GetAttribute(pDataElem, "needmat2", pData->needmat2);
			doc.GetAttribute(pDataElem, "num2", pData->num2);
			doc.GetAttribute(pDataElem, "needmat3", pData->needmat3);
			doc.GetAttribute(pDataElem, "num3", pData->num3);
			doc.GetAttribute(pDataElem, "needgold", pData->needgold);
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

	void VisitData(ComposeDataEntryVisitor<T>& visitor)
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

