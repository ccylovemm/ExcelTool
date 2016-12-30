// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     LotteryDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _LOTTERYDATALOADER_H
#define _LOTTERYDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct LotteryDataEntry
{
	LotteryDataEntry() : set(0), type(0), grade(0), needlvl(0), time1(0), CD1(0), protect(0), logtype(0){}
	virtual ~LotteryDataEntry(){ }
	virtual UInt32 GetKey() const { return set; }
	/**
	福袋编号id
	**/
	UInt8	set;

	/**
	福袋种类
	**/
	UInt8	type;

	/**
	积分段
	**/
	UInt32	grade;

	/**
	需求等级
	**/
	UInt16	needlvl;

	/**
	抽一次免费次数
	**/
	UInt16	time1;

	/**
	冷却时间（秒）
	**/
	UInt16	CD1;

	/**
	抽一次消耗数量
	**/
	string	cost1;

	/**
	抽10次消耗数量
	**/
	string	cost10;

	/**
	概率
	**/
	string	rates;

	/**
	保底品质
	**/
	UInt8	protect;

	/**
	日志类型
	**/
	UInt8	logtype;

	/**
	福袋活动名称
	**/
	string	activity;

	/**
	福袋名称
	**/
	string	name;
}; // LotteryDataEntry define end

//data visitor for the excel table
template <typename T>
class LotteryDataEntryVisitor
{
public:
	LotteryDataEntryVisitor(){ static_assert(std::is_base_of<LotteryDataEntry, T>::value != 0, "T must be inherited from LotteryDataEntry"); }
	virtual ~LotteryDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class LotteryDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	LotteryDataLoader(){ static_assert(std::is_base_of<LotteryDataEntry, T>::value != 0, "T must be inherited from LotteryDataEntry"); }
	~LotteryDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "set", pData->set);
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "grade", pData->grade);
			doc.GetAttribute(pDataElem, "needlvl", pData->needlvl);
			doc.GetAttribute(pDataElem, "time1", pData->time1);
			doc.GetAttribute(pDataElem, "CD1", pData->CD1);
			doc.GetAttribute(pDataElem, "cost1", pData->cost1);
			doc.GetAttribute(pDataElem, "cost10", pData->cost10);
			doc.GetAttribute(pDataElem, "rates", pData->rates);
			doc.GetAttribute(pDataElem, "protect", pData->protect);
			doc.GetAttribute(pDataElem, "logtype", pData->logtype);
			doc.GetAttribute(pDataElem, "activity", pData->activity);
			doc.GetAttribute(pDataElem, "name", pData->name);
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

	void VisitData(LotteryDataEntryVisitor<T>& visitor)
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

