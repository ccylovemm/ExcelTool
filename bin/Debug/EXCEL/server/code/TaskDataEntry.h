// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     TaskDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _TASKDATALOADER_H
#define _TASKDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct TaskDataEntry
{
	TaskDataEntry() : id(0), chapter(0), type(0), triggerLevel(0), preTask(0), timeLimit(0), abandomTimeLimit(0), acceptNpc(0), submitNpc(0), state(0), publishReward(0), unfinishReward(0), submitReward(0), failedReward(0){}
	virtual ~TaskDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	任务id
	**/
	UInt32	id;

	/**
	任务名
	**/
	string	name;

	/**
	章节TaskChapter
	**/
	UInt8	chapter;

	/**
	任务类型
	**/
	UInt8	type;

	/**
	触发等级
	**/
	UInt16	triggerLevel;

	/**
	前置任务
	**/
	UInt32	preTask;

	/**
	限时
	**/
	UInt32	timeLimit;

	/**
	放弃限时
	**/
	UInt32	abandomTimeLimit;

	/**
	奖励
	**/
	string	rewardsStr;

	/**
	描述
	**/
	string	describe;

	/**
	接取npc
	**/
	UInt32	acceptNpc;

	/**
	未接任务目标
	**/
	string	initTarget;

	/**
	未完成任务目标
	**/
	string	unfinishedTarget;

	/**
	提交npc
	**/
	UInt32	submitNpc;

	/**
	完成任务目标
	**/
	string	finishedTarget;

	/**
	是否自动挂机
	**/
	UInt32	state;

	/**
	发布任务对话
	**/
	string	publishWord;

	/**
	发布任务对话回复
	**/
	string	publishReply;

	/**
	是否显示发布任务奖励
	**/
	bool	publishReward;

	/**
	进行中任务对话
	**/
	string	unfinishWord;

	/**
	进行中任务对话回复
	**/
	string	unfinishReply;

	/**
	是否显示进行中任务奖励
	**/
	bool	unfinishReward;

	/**
	完成任务对话
	**/
	string	submitWord;

	/**
	完成任务对话回复
	**/
	string	submitReply;

	/**
	是否显示完成任务奖励
	**/
	bool	submitReward;

	/**
	失败任务对话
	**/
	string	failedWord;

	/**
	失败任务对话回复
	**/
	string	failedReply;

	/**
	是否显示失败任务奖励
	**/
	bool	failedReward;
}; // TaskDataEntry define end

//data visitor for the excel table
template <typename T>
class TaskDataEntryVisitor
{
public:
	TaskDataEntryVisitor(){ static_assert(std::is_base_of<TaskDataEntry, T>::value != 0, "T must be inherited from TaskDataEntry"); }
	virtual ~TaskDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class TaskDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	TaskDataLoader(){ static_assert(std::is_base_of<TaskDataEntry, T>::value != 0, "T must be inherited from TaskDataEntry"); }
	~TaskDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "chapter", pData->chapter);
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "triggerLevel", pData->triggerLevel);
			doc.GetAttribute(pDataElem, "preTask", pData->preTask);
			doc.GetAttribute(pDataElem, "timeLimit", pData->timeLimit);
			doc.GetAttribute(pDataElem, "abandomTimeLimit", pData->abandomTimeLimit);
			doc.GetAttribute(pDataElem, "rewardsStr", pData->rewardsStr);
			doc.GetAttribute(pDataElem, "describe", pData->describe);
			doc.GetAttribute(pDataElem, "acceptNpc", pData->acceptNpc);
			doc.GetAttribute(pDataElem, "initTarget", pData->initTarget);
			doc.GetAttribute(pDataElem, "unfinishedTarget", pData->unfinishedTarget);
			doc.GetAttribute(pDataElem, "submitNpc", pData->submitNpc);
			doc.GetAttribute(pDataElem, "finishedTarget", pData->finishedTarget);
			doc.GetAttribute(pDataElem, "state", pData->state);
			doc.GetAttribute(pDataElem, "publishWord", pData->publishWord);
			doc.GetAttribute(pDataElem, "publishReply", pData->publishReply);
			doc.GetAttribute(pDataElem, "publishReward", pData->publishReward);
			doc.GetAttribute(pDataElem, "unfinishWord", pData->unfinishWord);
			doc.GetAttribute(pDataElem, "unfinishReply", pData->unfinishReply);
			doc.GetAttribute(pDataElem, "unfinishReward", pData->unfinishReward);
			doc.GetAttribute(pDataElem, "submitWord", pData->submitWord);
			doc.GetAttribute(pDataElem, "submitReply", pData->submitReply);
			doc.GetAttribute(pDataElem, "submitReward", pData->submitReward);
			doc.GetAttribute(pDataElem, "failedWord", pData->failedWord);
			doc.GetAttribute(pDataElem, "failedReply", pData->failedReply);
			doc.GetAttribute(pDataElem, "failedReward", pData->failedReward);
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

	void VisitData(TaskDataEntryVisitor<T>& visitor)
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

