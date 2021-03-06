/* This file is part of Strigi Desktop Search
 *
 * Copyright (C) 2006 Jos van den Oever <jos@vandenoever.info>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
#ifndef STRIGI_PYTHONINDEXMANAGER_H
#define STRIGI_PYTHONINDEXMANAGER_H

#ifdef SWIGGING
  %feature("director") PythonIndexManager;
  %extend PythonIndexManager {
    static void addFactory(StreamEndAnalyzerFactory* factory){
      PythonAnalyzerFactoryFactory::seaf.push_back(factory);
    }
    static void addFactory(StreamEventAnalyzerFactory* factory){
      PythonAnalyzerFactoryFactory::sevaf.push_back(factory);
    }
    static void addFactory(StreamLineAnalyzerFactory* factory){
      PythonAnalyzerFactoryFactory::slaf.push_back(factory);
    }
    static void addFactory(StreamSaxAnalyzerFactory* factory){
      PythonAnalyzerFactoryFactory::ssaf.push_back(factory);
    }
    static void addFactory(StreamThroughAnalyzerFactory* factory){
      PythonAnalyzerFactoryFactory::staf.push_back(factory);
    }
    static void clearFactories(){
      PythonAnalyzerFactoryFactory::seaf.clear();
      PythonAnalyzerFactoryFactory::sevaf.clear();
      PythonAnalyzerFactoryFactory::slaf.clear();
      PythonAnalyzerFactoryFactory::ssaf.clear();
      PythonAnalyzerFactoryFactory::staf.clear();
    }
  }
#endif

/**
 * Abstract interface that manages access to the IndexReader and IndexWriter
 * instances provided by a particular index backend.
 *
 * The IndexManager handles all access to a particular index through the
 * IndexReader and IndexWriter objects contained within it.
 * The functions of IndexManager are threadsafe, but the functions provided
 * by the IndexReader and IndexWriter need not be. IndexReader and IndexWriter
 * objects may not be accessed from different threads. When access to an
 * index from a particular thread is required, the functions indexReader()
 * and indexWriter() provide instances of the respective classes that may
 * be used in the active thread.
 **/
class PythonIndexManager 
#ifndef SWIGGING
  : public IndexManager
#endif
{
public:
    PythonIndexManager(){
    }
    virtual ~PythonIndexManager() {
    }
    
    virtual PythonIndexWriter* pythonIndexWriter() = 0;
    
#ifndef SWIGGING
    /**
     * Provide access to an IndexReader object that may be used in the active
     * thread.
     *
     * @return a pointer to an IndexReader that reads from the index that is
     *         managed by this instance of IndexManager
     **/
    virtual IndexReader* indexReader(){
      std::__throw_runtime_error("indexReader is not implemented");
    }
    
    
    virtual IndexWriter* indexWriter(){
      return pythonIndexWriter();
    }
    
#endif
    
};


#endif
